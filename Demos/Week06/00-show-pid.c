/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08: Fri 27 Oct 2023 07:00
 * REV07: Tue 24 Mar 2020 12:00
 * REV06: Wed 29 Aug 2018 16:00
 * REV05: Wed 01 Nov 2017 13:00
 * START: Mon 24 Oct 2016 09:00
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(void) {
   printf("  [[[ This is 00-show-pid: PID[%d] PPID[%d] ]]]\n", getpid(), getppid());
}

/*
# INFO: Get PID dan PPID.
# INFO:                   PID  means Process ID (identification)
# INFO:                   to get PID, call system function getpid().
# INFO:                   PPID means Parent Process ID
# INFO:                   to get PPID, call system function getppid().
 */

