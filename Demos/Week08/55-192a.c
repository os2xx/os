/*
 Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV03: Sat 28 Oct 2023 12:00
 * REV02: Wed 25 Mar 2020 12:00
 * REV01: Sun 15 Dec 2019 15:00
 * START: Mon 09 Dec 2019 16:00

# INFO: UAS 2019-2 (final term)
# INFO:                   To run:   ./55-192a 

*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED
#define SFILE            "demo-file.bin"

typedef  struct {
   sem_t  sync1;
   sem_t  sync2;
   pid_t  relative;
} myshare;

myshare* mymap;

void flushprintf(char* tag){
   printf("PIDr[%d] %s\n", 
      getpid() + mymap->relative, tag);
   fflush(NULL);
}

void main(void) {
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   truncate(SFILE, ssize);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   mymap->relative = 1000 - getpid();
   sem_init (&(mymap->sync1), 1, 0);
   sem_init (&(mymap->sync2), 1, 0);
   flushprintf("START");
   if (!fork())
      execlp("./56-192b", "./56-192b", NULL);
   wait(NULL);
   flushprintf("EXIT");
}

