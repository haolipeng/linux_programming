//
// Created by root on 22-5-20.
//

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

int main(){
    int ret = 0;
    char buf[MSG_MAX_LENGTH + 1] = {0};

    //1.create socket
    int listen_fd = socket(AF_UNIX,SOCK_STREAM,0);
    if(-1 == listen_fd){
        return -1;
    }

    //2.bind unix addr to socket
    struct sockaddr_un unix_socket_addr;
    memset(&unix_socket_addr,sizeof(sockaddr_un),0);
    unix_socket_addr.sun_family = AF_UNIX;
    strcpy(unix_socket_addr.sun_path,UNIX_SOCKET_PATH);
    ret = bind(listen_fd,(const struct sockaddr*)&unix_socket_addr,sizeof(unix_socket_addr));
    if(-1 == ret){
        return -1;
    }

    //3.listen socket
    ret = listen(listen_fd,BACKLOG);
    if(-1 == ret){
        return -1;
    }

    //4.accept conn on listen_fd
    while(1){
        int client_fd = accept(listen_fd,NULL,NULL);
        if(client_fd < 0){
            return -1;
        }
        //read data
        read(client_fd,buf,MSG_MAX_LENGTH);
        printf("read from client:%s\n",buf);

        //write data
        write(client_fd,buf,MSG_MAX_LENGTH);
        printf("write to client:%s\n",buf);
        break;
    }

    unlink(UNIX_SOCKET_PATH);
    return 0;
}