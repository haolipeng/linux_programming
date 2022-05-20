#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <sys/un.h>
#include <cstdio>
#include <unistd.h>
#include <unistd.h>

#define UNIX_SOCKET_PATH "/tmp/echo_unix_socket"
#define BACKLOG 5
#define MSG_MAX_LENGTH 100

int main() {
    int ret = 0;
    char buf[MSG_MAX_LENGTH + 1] = {0};

    //1.create socket
    int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (-1 == socket_fd) {
        return -1;
    }

    //2.bind unix addr to socket
    struct sockaddr_un unix_socket_addr;
    memset(&unix_socket_addr, sizeof(sockaddr_un), 0);
    unix_socket_addr.sun_family = AF_UNIX;
    strcpy(unix_socket_addr.sun_path, UNIX_SOCKET_PATH);

    ret = connect(socket_fd, reinterpret_cast<const sockaddr *>(&unix_socket_addr), sizeof(unix_socket_addr));
    if(ret < 0){
        return -1;
    }

    for (;;){
        fgets(buf,MSG_MAX_LENGTH,stdin);
        int len = strlen(buf);

        //write data
        if(write(socket_fd,buf,len) != len){
            fprintf(stderr,"write error\n");
            return -1;
        }

        //read data
        if(read(socket_fd,buf,len) != len){
            fprintf(stderr,"read error\n");
            return -1;
        }

        printf("read from server:%s\n",buf);
        break;
    }

    unlink(UNIX_SOCKET_PATH);
    return 0;
}