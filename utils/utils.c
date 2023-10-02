#include "utils.h"
#include <sys/socket.h>
#include <arpa/inet.h> /*for inet_ntop & inet_pton*/
#include <stdint.h>
#include <string.h>

void
apply_mask(char *prefix, char mask, char *str_prefix){

    uint32_t binary_prefix = 0;
    uint32_t subnet_mask = 0xFFFFFFFF;

    if(mask == 32){
        strncpy(str_prefix, prefix, 16);
        str_prefix[15] = '\0';
        return;
    }
    /*Convert Given IP address into binary format*/
    inet_pton(AF_INET, prefix, &binary_prefix);
    binary_prefix = htonl(binary_prefix);

    /*Compute Mask in binary format as well*/
    subnet_mask = subnet_mask << (32 - mask);

    /*Perform logical AND to apply mask on IP address*/
    binary_prefix = binary_prefix & subnet_mask;

    /*Convert the Final IP into string format again*/
    binary_prefix = htonl(binary_prefix);
    inet_ntop(AF_INET, &binary_prefix, str_prefix, 16);
    str_prefix[15] = '\0';
}

void
layer2_fill_with_broadcast_mac(char *mac_array){
    if(mac_array)
        memset(mac_array, 'f', 12);
}

