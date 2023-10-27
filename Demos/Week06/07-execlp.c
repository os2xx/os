/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02: Fri 27 Oct 2023 14:00
 * REV01: Tue 24 Mar 2020 16:00
 * START: Mon 09 Dec 2019 16:00
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char* argv[]) {
   printf("START %11s PID[%d]\n", argv[0], getpid());
   if(argc == 1) {
      execlp(argv[0], "EXECLP", "WhatEver", NULL);
   } else {
      printf("ELSE  %11s PID[%d]\n", argv[1], getpid());
   }
   printf("END   %11s PID[%d]\n", argv[0], getpid());
}

/*
# INFO: System call "execlp()"
# INFO:                   Run: 
# INFO:                   ./07-execlp  ONE_ARGUMENT
 */


