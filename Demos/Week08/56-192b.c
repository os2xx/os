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
# INFO:                   Run from: ./54-192a

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

void main(int argc, char* argv[]) {
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   flushprintf("START");
   if(argc == 1) {
      if (!fork()) {
         sem_post (&(mymap->sync1));
         sem_wait (&(mymap->sync2));
         flushprintf("FORK CHILD");
      } else {
         sem_wait (&(mymap->sync1));
         flushprintf("FORK PARENT");
         sem_post (&(mymap->sync2));
      }
      execlp(argv[0], argv[0], "XYZZY", NULL);
   } 
   wait(NULL);
   flushprintf("EXIT");
}

