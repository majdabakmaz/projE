
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int read_word(int fd){
    int c;
    if(read(fd, &c, sizeof(c) ) < 0) printf("greska");
    return c;
}

short read_half(int fd){
    short c;
    if (read(fd, &c, sizeof(c))<0){ 
        printf("error\n");
        printf("%s\n", strerror(errno));
    }
    else{
        printf("%d\n", c);
    }
    return c;
}

void write_word(int fd, int word){
      if(write(fd, &word, sizeof(word)) < 0 ) printf("greska");
}
void write_half(int fd, short word){
    if (write(fd, &word, sizeof(word)) != sizeof(word)) printf("greska_write\n");
}