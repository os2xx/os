/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV09: Fri 27 Oct 2023 18:00
 * REV08: Tue 24 Mar 2020 16:00
 * REV07: Wed 27 Feb 2019 19:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV03: Wed 01 Nov 2017 14:00
 * START: Sun 04 Dec 2016 00:00
 *
 * wait()     =  suspends until its child terminates. 
 * fflush()   =  flushes the user-space buffers.
 * getppid()  =  get parent PID
 * ASSUME pid >= 1000 && pid > ppid **
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define  NN 2

void main(void) {
   int ii, rPID, rPPID, id1000=getpid();
   for (ii=1; ii<=NN; ii++) {
      fork();
      wait(NULL);
      rPID = getpid()-id1000+1000; /* "relative" */
      rPPID=getppid()-id1000+1000; /* "relative" */
      if (rPPID < 1000 || rPPID > rPID) rPPID=999;
      printf("Loop [%d] - rPID[%d] - rPPID[%4d]\n", ii, rPID, rPPID);
      fflush(NULL);
   }
}

/*
# INFO: UTS 2016-2 (midterm)
 */

