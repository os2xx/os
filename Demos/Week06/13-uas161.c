/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV19: Fri 27 Oct 2023 18:00
 * REV10: Tue 24 Mar 2020 16:00
 * REV09: Fri 01 Nov 2019 01:00
 * REV08: Wed 27 Feb 2019 19:00
 * REV06: Mon 04 Apr 2016 00:00
 * START: Fri 01 Jan 2016 00:00
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(void) {
   pid_t  pid1, pid2, pid3;

   pid1 = pid2 = pid3 = getpid();
   printf(" 2016   2015   Lainnya\n=====================\n");
   printf("[%5.5d][%5.5d][%5.5d]\n", pid1, pid2, pid3);
   fork(); 
   pid1 = getpid();
   wait(NULL);
   pid2 = getpid();
   if(!fork()) {
     pid2 = getpid();
     fork();
   }
   pid3 = getpid();
   wait(NULL);
   printf("[%5.5d][%5.5d][%5.5d]\n", pid1, pid2, pid3);
}

/*
# INFO: UTS 2016-1 (midterm)
 */

