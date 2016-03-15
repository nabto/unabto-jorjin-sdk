#include <unabto/unabto_external_environment.h>

#ifdef __cplusplus
extern "C" {
#include "sockets.h"
}
#endif

bool nabto_init_socket(uint32_t localAddr, uint16_t* localPort, nabto_socket_t* sock)
{

    nabto_socket_t sd;
    
    NABTO_LOG_TRACE(("Open socket: ip=" PRIip ", port=%u", MAKE_IP_PRINTABLE(localAddr), (int)*localPort));
    
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd == -1) {
        NABTO_LOG_ERROR(("Unable to create socket: (%i) '%s'.", errno, strerror(errno)));
        return false;
    }
    
    {
        struct sockaddr_in sa;
        int status;
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = AF_INET;
        sa.sin_addr.s_addr = htonl(localAddr);
        sa.sin_port = htons(*localPort);
        
        status = bind(sd, (struct sockaddr*)&sa, sizeof(sa));
        
        if (status < 0) {
            NABTO_LOG_ERROR(("Unable to bind socket: (%i) '%s' localport %i", errno, strerror(errno), *localPort));
            close(sd);
            return false;
        }

        // Nonblocking flags
        int flags = fcntl(sd, F_GETFL, 0);
        if (flags == -1) flags = 0;
        fcntl(sd, F_SETFL, flags | O_NONBLOCK);
        
        *sock = sd;
    }

    {
        struct sockaddr_in sao;
        socklen_t len = sizeof(sao);
        if ( getsockname(*sock, (struct sockaddr*)&sao, &len) != -1) {
            *localPort = htons(sao.sin_port);
        } else {
            NABTO_LOG_ERROR(("Unable to get local port of socket: (%i) '%s'.", errno, strerror(errno)));
        }
    }
    
    NABTO_LOG_TRACE(("nabto_init_socket socket=%u localPort=%u", (uint8_t) *sock, *localPort));
    return true;
    
}

void nabto_close_socket(nabto_socket_t* sock)
{
    NABTO_LOG_TRACE(("nabto_close_socket socket=%u", (uint8_t) *sock));

    close(*sock);
    *sock = NABTO_INVALID_SOCKET;
}

ssize_t nabto_read(nabto_socket_t sock,
                   uint8_t*       buf,
                   size_t         maxLength,
                   uint32_t*      addr,
                   uint16_t*      port)
{
    
    struct sockaddr_in sa;
    socklen_t addrlen = sizeof(sa);

    ssize_t recvLength = recvfrom(sock, buf, maxLength, 0, (struct sockaddr*)&sa, &addrlen);

    if (recvLength < 0 || recvLength == 0) {
        return 0;
    }
    
    *addr = ntohl(sa.sin_addr.s_addr);
    *port = ntohs(sa.sin_port);

    return recvLength;
    
}

ssize_t nabto_write(nabto_socket_t sock,
                    const uint8_t* buf,
                    size_t         len,
                    uint32_t       addr,
                    uint16_t       port)
{
    
    int res;
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = htonl(addr);
    sa.sin_port = htons(port);
    
    res = sendto(sock, buf, (int)len, 0, (struct sockaddr*)&sa, sizeof(sa));
    if (res < 0) {
        int status = errno;
        NABTO_NOT_USED(status);
        NABTO_LOG_ERROR(("ERROR: %s (%i) in nabto_write()", strerror(status), (int) status));
    }
    return res;
}
