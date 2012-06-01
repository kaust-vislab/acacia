import sys
import zmq
import threading
import Queue
import pytest

# use libev - gevent

def zmq_req(url, control, expected):
    ctx = zmq.Context()
    rep = ctx.socket(zmq.REP)
    rep.bind(url)
    while True:
        rv = rep.poll(1000)
        if rv:
            msg = rep.recv()
            assert msg == expected
            break
        try:
            # will loop until something is sent down the queue
            control.get(block=False)
        except Empty:
            continue
        

def test():
    url = 'tcp://127.0.0.1:12345'
    msg = "hello there"
    control_queue = Queue.Queue()
    proc = threading.Thread(target=zmq_req, args=(url, control_queue, msg,))
    proc.start()
    
    ctx = zmq.Context()
    req = ctx.socket(zmq.REQ)
    req.connect(url)
    req.send('hello ther')
    proc.join(1)
    still_alive = proc.is_alive()
    if still_alive:
        control_queue.put("stop")
        proc.join()
        pytest.fail('zmq reply process is still running')
    

