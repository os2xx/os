/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 14:00
 * REV07: Tue 24 Mar 2020 16:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV03: Mon 30 Oct 2017 11:00
 * REV00: Mon 24 Oct 2016 10:00
 * START: Thu 01 Jan 2015 00:00
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
   int value;

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);

   value=fork();
   wait(NULL);
   printf("I am PID[%4d] -- The fork() return value is: %4d)\n", getpid(), value);
}

/*
# INFO: System call "fork()"
 */

