# =============================================================================
#
#         Author:  Christopher Knox, christopher.knox@kaust.edu.sa
#   Organization:  KAUST Visualization Lab
#      Copyright:  All rights reserved 2012.
#
# =============================================================================

from acacia import Reader
from stat import S_IFREG
from threading import Thread
import zmq
import random


def dummy_supervisor(request, reply):
    ctx = zmq.Context()
    sock = ctx.socket(zmq.DEALER)
    sock.bind('tcp://*:6767')
    req = sock.recv_json()
    assert req == request
    req['result'] = reply
    sock.send_json(req)
    sock.send_json({'shutdown': 'now'})


def operation_helper(request, reply):
    rep_thread = Thread(target=dummy_supervisor, args=(request, reply,))
    rep_thread.start()

    acacia_reader = Reader('tcp://localhost:6767')
    res = acacia_reader.operation(request)
    assert res == reply


def test_readdir():
    'tests to make sure that the readdir functionality works'
    reply = ['.', '..', 'data.am']
    request = {'readdir': {'path': '.'}}
    operation_helper(request, reply)


def test_getattr():
    'ensures that getattr functionality works'
    reply = dict(st_mode=(S_IFREG | 0444), st_size=1024)
    request = {'getattr': {'path': 'data.am'}}
    operation_helper(request, reply)


def test_read():
    tmp = range(64)
    random.shuffle(tmp)
    reply = bytearray(tmp)
    request = {'read': {'path': 'data.am',
                        'offset': 0,
                        'size': 64}}
    operation_helper(request, reply)