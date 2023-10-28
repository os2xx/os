/*
 Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
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
 
 * REV07: Sat 28 Oct 2023 12:00
 * REV06: Wed 25 Mar 2020 12:00
 * REV05: Mon 28 Oct 2019 20:00
 * REV03: Mon 10 Dec 2018 18:00
 * START: Wed 14 Nov 2018 20:00

# INFO: UAS 2018-2 (final term)
# INFO:                   To run:   ./51-182 

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
   sem_t  sync[3];
   int    share;
   int    loop;
   pid_t  relative;
} myshare;

myshare* mymap;

void flushprintf(char* tag1, char* tag2){
   printf("%s[%s] loop%d relative(%d)\n", 
      tag1, tag2, mymap->loop, 
      getpid()  + mymap->relative);
   fflush(NULL);
}

#define MAIN "51:182 "
#define ADD1 "52:182a"
#define SUB1 "53:182b"

void main(void) {
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   truncate(SFILE, ssize);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   mymap->share    = 0;
   mymap->loop     = 6;
   mymap->relative = 1000 - getpid();
   sem_init (&(mymap->sync[0]), 1, 0);
   sem_init (&(mymap->sync[1]), 1, 0);
   sem_init (&(mymap->sync[2]), 1, 0);
   flushprintf(MAIN, "EXEC");
   if (!fork())
      execlp("./52-182a", ADD1, NULL);
   if (!fork()) 
      execlp("./53-182b", SUB1, NULL);
   do {
      sleep(1);
      flushprintf(MAIN, "LOOP");
   } while (--mymap->loop);
   flushprintf(MAIN, "WAIT");
   sem_wait (&(mymap->sync[0]));
   sem_wait (&(mymap->sync[0]));
   if      (mymap->share > 1500)
      flushprintf("SHARE +/-", "2000");
   else if (mymap->share > 500)
      flushprintf("SHARE +/-", "1000");
   else 
      flushprintf("SHARE +/-", "0");
   wait(NULL);
   wait(NULL);
   flushprintf(MAIN, "EXIT");
   close(fd);
}

//       1         2         3         4
// 4567890123456789012345678901234567890

