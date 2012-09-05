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
        self.readdir_rep = ctx.socket(zmq.REP)
        self.readdir_rep.bind('inproc://readdir')
        self.dealer = ctx.socket(zmq.DEALER)
        self.dealer.connect(url)

    def run(self):
        'starts the thread'
        poller = zmq.Poller()
        poller.register(self.readdir_rep, zmq.POLLIN)
        poller.register(self.dealer, zmq.POLLIN)
        while True:
            socks = dict(poller.poll())
            if self.readdir_rep in socks:
                if socks[self.readdir_rep] == zmq.POLLIN:
                    query = self.readdir_rep.recv()
                    self.dealer.send(query)
            elif self.dealer in socks:
                if socks[self.dealer] == zmq.POLLIN:
                    res = self.dealer.recv_json()
                    if res == {'shutdown': 'now'}:
                        break
                    self.readdir_rep.send_json(res)


class Reader(object):
    def __init__(self, url):
        ctx = zmq.Context()
        self.interface = ReaderInterface(url, ctx)
        self.interface.start()
        self.readdir_req = ctx.socket(zmq.REQ)
        self.readdir_req.connect('inproc://readdir')

    def readdir(self):
        ''' returns the contents of the directory
            currently only support a single flat directory
        '''
        query = {'readdir': {'dir': '.'}}
        self.readdir_req.send_json(query)
        response = self.readdir_req.recv_json()
        return response['result']


# class ClientContext(Operations):
#     """class the handles fuse filesystem operations"""
#     def __init__(self):
