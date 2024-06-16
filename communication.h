#include "net.h"
#include "graph.h"

#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

static int BASE_UDP_ADDRESS = 40000;

int init_udp_sock(node_t *node);
