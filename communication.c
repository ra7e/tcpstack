#include "communication.h"
#include "net.h"
#include "graph.h"

#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

static int get_new_udp_number ()
{
    return BASE_UDP_ADDRESS++;
}

int init_udp_sock(node_t *node)
{
    int sock_fd = 0;
    struct sockaddr_in node_addr;

    if (!node)
    {
        BAD_PARAMS_ERROR();
        return -1;
    }

    node->udp_port_num = get_new_udp_number();

    sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    node_addr.sin_family = AF_INET;
    node_addr.sin_port = htons(node->udp_port_num);
    node_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock_fd, (struct sockaddr *)&node_addr, sizeof(struct sockaddr)) == -1){
        printf("Failed binding socket at line %d, file %s\n", __LINE__, __FILE__);
        return -2;
    }
    
    node->udp_port_sock = sock_fd;
}