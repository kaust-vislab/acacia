# =============================================================================
#
#         Author:  Christopher Knox, christopher.knox@kaust.edu.sa
#   Organization:  KAUST Visualization Lab
#      Copyright:  All rights reserved 2012.
#
# =============================================================================

from acacia import Reader
from threading import Thread
import zmq


def dummy_readdir(desired):
    ctx = zmq.Context()
    sock = ctx.socket(zmq.DEALER)
    sock.bind('tcp://*:6767')
    req = sock.recv_json()
    assert req == {'readdir': {'dir': '.'}}
    req['result'] = desired
    sock.send_json(req)
    sock.send_json({'shutdown': 'now'})


def test_readdir():
    'tests to make sure that the readdir functionality works'
    desired = ['.', '..', 'data.am']
    rep_thread = Thread(target=dummy_readdir, args=(desired,))
    rep_thread.start()

    acacia_reader = Reader('tcp://localhost:6767')
    res = acacia_reader.readdir()
    assert res == desired
