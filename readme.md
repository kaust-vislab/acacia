# Acacia Filesystem

The acacia filesystem is a read only filesystem for clusters that enables all the nodes of a cluster to read the same file in as efficient a way as possible.

# Design

## Server
- starts and creates a zmq endpoint which listens for incoming information requests
	- the response to queries/commands are multicast to all the participating nodes
	- this endpoint handles readdir and getattr requests
	- open requests result in the spawning of a thread to handle a specific file and the creation of another multicast group - clients then need to join this multicast group. Might not implement this straight away.
- read requests for files a processed in 64k blocks which are sent in chunks of 8192 bytes per message

**Problems:** How to distinguish between duplicate requests and re-read or missed read requests? Probably make the client ask again on a unicast channel?





