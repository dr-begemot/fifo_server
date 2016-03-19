// fifo/pipe-сервер
// 
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include <errno.h>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>

//#include <fcntl.h>
//#include <sys/stat.h>
//#include <sys/types.h>
//#include <unistd.h>

#define NAMEDPIPE_NAME "/named_pipe"
#define BUFSIZE        50

int main (int argc, char ** argv) {
    int fd, len;
    char buf[BUFSIZE];

    if ( mkfifo(NAMEDPIPE_NAME, 0777) ) {
        perror("mkfifo");
        return 1;
    }
    printf("%s is created\n", NAMEDPIPE_NAME);

    if ( (fd = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0 ) {
        perror("open");
        return 1;
    }
    printf("%s is opened\n", NAMEDPIPE_NAME);

    do {
        memset(buf, '\0', BUFSIZE);
        if ( (len = read(fd, buf, BUFSIZE-1)) <= 0 ) {
            perror("read");
            close(fd);
            remove(NAMEDPIPE_NAME);
            return 0;
        }
        printf("Incomming message (%d): %s\n", len, buf);
    } while ( 1 );
}

/*
 //
 //  main.cpp
 //  fif0_server
 //
 //  Created by dr_Begemot on 16.03.16.
 //  Copyright © 2016 dr_Begemot. All rights reserved.
 //
 
 #include <iostream>
 
 int main(int argc, const char * argv[]) {
 // insert code here...
 std::cout << "Hello, World!\n";
 return 0;
 }
//*/