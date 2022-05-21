#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

//
// Created by root on 22-5-20.
//
void dup2_test(int fd) {
    dup2(fd,1);

    printf("I will printed in the file\n");
}

int main(){
    //1.open function return a file descriptor file desc to file "dup.txt"
    int file_desc = open("dup.txt",O_WRONLY | O_APPEND |O_CREAT);
    if(file_desc < 0){
        printf("open file error\n");
    }

    //2.copy file_desc as copy_desc
    int copy_desc = dup(file_desc);

    //3.write string to file use file_desc and copy_desc
    char buf[] = "this will be output to file dup.txt\n";
    write(file_desc,buf,sizeof(buf));

    write(copy_desc,buf,sizeof(buf));

    dup2_test(file_desc);
}