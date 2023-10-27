/*
 * Copyright (C) 2005-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV19: Fri 27 Oct 2023 14:00
 * REV09: Tue 24 Mar 2020 16:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV05: Wed 01 Nov 2017 13:00
 * REV00: Mon 24 Oct 2016 10:00
 * START: Sat 01 Jan 2005 00:00
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*************************************************** main ** */
void main(void) {
   pid_t val1, val2, val3;
   val3 = val2 = val1 = 1000;
   printf("PID==[%5.5d] ==== ======= ==== =======\n", getpid());
   //
   // NO FORK()
   //
   printf("VAL1=[%5.5d] VAL2=[%5.5d] VAL3=[%5.5d]\n", val1, val2, val3);
}


/*
# INFO: System call "fork()"
# INFO:                   Compare 
# INFO:                      "06a-fork.c" [no    fork()],
# INFO:                      "06b-fork.c" [one   fork()],
# INFO:                      "06c-fork.c" [two   fork()s],
# INFO:                      "06d-fork.c" [three fork()s],
 */

