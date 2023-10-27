/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV09: Fri 27 Oct 2023 14:00
 * REV08: Tue 24 Mar 2020 13:00
 * REV06: Wed 16 Aug 2018 16:00
 * REV04: Wed 01 Nov 2017 13:00
 * START: Mon 24 Oct 2016 09:00
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   printf("Start:           PID[%5.5d] PPID[%5.5d]\n", getpid(), getppid());
   fflush(NULL);
   if (fork() == 0) {
      execlp("./00-show-pid", "00-show-pid", NULL); // ** LOOK THIS! **
      printf("Child:           ");                  // Never Executed!
   } else {
      wait(NULL);
      printf("Parent:          ");
   }
   printf(        "PID[%5.5d] PPID[%5.5d]  <<< <<< <<<\n", getpid(), getppid());
}

/*
# INFO: System call "fork()" and "execlp()"
# INFO:                   Compare "05a-fork.c" and "05b-fork.c".
# INFO:                   See also "00-show-pid.c" and system call "execlp()".
 */


