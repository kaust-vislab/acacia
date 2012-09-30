# =============================================================================
#
#         Author:  Christopher Knox, christopher.knox@kaust.edu.sa
#   Organization:  KAUST Visualization Lab
#      Copyright:  All rights reserved 2012.
#
# =============================================================================

import zmq
#from fuse import Operations, fuse_get_context
from threading import Thread


class ReaderInterface(Thread):
    'handles all the clients communication with the supervisor and servers'
    def __init__(self, url, ctx):
        Thread.__init__(self)
        self.operation_rep = ctx.socket(zmq.REP)
        self.operation_rep.bind('inproc://operation')
        self.dealer = ctx.socket(zmq.DEALER)
        self.dealer.connect(url)

    def run(self):
        'starts the thread'
        poller = zmq.Poller()
        poller.register(self.operation_rep, zmq.POLLIN)
        poller.register(self.dealer, zmq.POLLIN)
        while True:
            socks = dict(poller.poll())
            if self.operation_rep in socks:
                if socks[self.operation_rep] == zmq.POLLIN:
                    query = self.operation_rep.recv()
                    self.dealer.send(query)
            elif self.dealer in socks:
                if socks[self.dealer] == zmq.POLLIN:
                    res = self.dealer.recv_json()
                    if res == {'shutdown': 'now'}:
                        break
                    self.operation_rep.send_json(res)


class Reader(object):
    def __init__(self, url):
        ctx = zmq.Context()
        self.interface = ReaderInterface(url, ctx)
        self.interface.start()
        self.operation_req = ctx.socket(zmq.REQ)
        self.operation_req.connect('inproc://operation')

    def operation(self, command):
        ''' returns the contents of the directory
            currently only support a single flat directory
        '''
        self.operation_req.send_json(command)
        response = self.operation_req.recv_json()
        return response['result']


# class ClientContext(Operations):
#     """class the handles fuse filesystem operations"""
#     def __init__(self):
