/*
 * Copyright (C) 2005-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 19:00
 * REV07: Tue 24 Mar 2020 16:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV03: Mon 30 Oct 2017 15:00
 * REV00: Wed 03 May 2017 17:00
 * START: Sat 01 Jan 2005 00:00
 *
 * fflush(NULL): flushes all open output streams
 * fork():       creates  a new process by cloning
 * getpid():     get PID (Process ID)
 * wait(NULL):   wait until the child is terminated
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(void) {
   int firstPID = (int) getpid();
   int   RelPID;

   fork();
   wait(NULL);
   fork();
   wait(NULL);
   fork();
   wait(NULL);

   RelPID=(int)getpid()-firstPID+1000;
   printf("RelPID: %d\n", RelPID);
   fflush(NULL);
}

/*
# INFO: UTS 2017-1 (midterm)
 */

