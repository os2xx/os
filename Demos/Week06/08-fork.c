/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 14:00
 * REV07: Tue 24 Mar 2020 16:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV02: Thu 26 Oct 2017 12:00
 * REV01: Mon 24 Oct 2016 10:00
 * START: Sat 01 Jan 2005 00:00
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(void) {
   int ii=0;
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   if (fork() == 0) ii++;
   wait(NULL);
   printf ("Result = %d \n",ii);
   exit(0);
}

/*
# INFO: System call "fork()"
 */

