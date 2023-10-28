/*
 * Copyright (C) 2015-2018 CC BY-SA 3.0 adapted from https://stackoverflow.com/
 *            questions/32205396/share-posix-semaphore-among-multiple-processes
 * Copyright (C) 2005-2023 BinKadal, Sdn. Bhd.
 * You are free to SHARE (copy and redistribute the material in any medium or
 * format) and to ADAPT (remix, transform, and build upon the material for any
 * purpose, even commercially).  This program is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05: Sat 28 Oct 2023 12:00
 * REV04: Sat 11 Apr 2020 17:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV02: Wed 18 Apr 2018 22:00
 * START: Thu 01 Jan 2015 00:00
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

char parent_message[] = "You say Hello";  // parent process will write this message
char child_message[]  = "And I say Goodbye"; // child process will then write this one

int main(void) {
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_ANONYMOUS | MAP_SHARED;
  char* shmem = mmap(NULL, 128, protection, visibility, 0, 0);
  memcpy(shmem, parent_message, sizeof(parent_message));
  int pid = fork();
  if (pid == 0) {
    printf("Child read:  %s\n", shmem);
    memcpy(shmem, child_message, sizeof(child_message));
    printf("Child wrote: %s\n", shmem);
  } else {
    printf("Parent read: %s\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }
}


/*
 * TAKE NOTE (RMS)
 * TESTED ON WSL Windows 10:
 
 $ ./22-hello-goodbye 
 Parent read: You say Hello
 Child read:  You say Hello
 Child wrote: And I say Goodbye
 After 1s, parent read: And I say Goodbye
 $

 */

