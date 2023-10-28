/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This is free software.
 * REV04: Sat 28 Oct 2023 10:00
 * REV03: Tue 24 Mar 2020 16:00
 * REV02: Mon 11 Dec 2017 17:00
 * START: Sun 03 Dec 2017 18:00
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LOOP   3
#define OFFSET 1000

void main(void) {
   int basePID = getpid() - OFFSET;

   for (int ii=0; ii < LOOP; ii++) {
      if(!fork()) {
         printf("PID[%d]-PPID[%d]\n", 
                 getpid()  - basePID, 
                 getppid() - basePID);
         fflush(NULL);
      }
      wait(NULL);
   }
}

/*
# INFO: UTS 2017-2 (midterm)
 */

