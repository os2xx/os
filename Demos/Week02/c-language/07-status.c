/*
 * Copyright (C) 2013-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to function getpid() and getppid().
 * REV06: Thu 26 Oct 2023 19:00
 * REV05: Fri 07 Feb 2020 01:00
 * REV04: Tue 25 Sep 2018 11:00
 * START: Tue 01 Jan 2013 00:00
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(void) {
   printf("Process Identifier (PID) [%5.5d] -- Parent PID (PPID[%5.5d])\n", getpid(), getppid());
   sleep(1);
}

/*
 * TAKE NOTE(AII, MG)
 * In Linux, an executable stored on disk is called a 
 * program,
 * and a program loaded into memory and running is 
 * called a process. 
 * When a process is started, it is given a unique 
 * number called process ID (PID)
 * that identifies that process to the system
 * 
 * Each process is assigned a parent process ID (PPID) 
 * that tells which process started it. 
 * The PPID is the PID of the process’s parent.
 *
 * To see PID and PPID in current process you can use 
 * getpid() and getppid()
 *
 * sleep() function delays program execution for a 
 * given number of seconds
 */

