/*
 * Copyright (C) 2015-2018 CC BY-SA 3.0 adapted from https://stackoverflow.com/
 *            questions/32205396/share-posix-semaphore-among-multiple-processes
 * Copyright (C) 2005-2023 BinKadal, Sdn. Bhd.
 * You are free to SHARE (copy and redistribute the material in any medium or
 * format) and to ADAPT (remix, transform, and build upon the material for any
 * purpose, even commercially).  This program is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05: Sat 28 Oct 2023 12:00
 * REV04: Sat 11 Apr 2020 17:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV02: Wed 18 Apr 2018 22:00
 * START: Thu 01 Jan 2015 00:00
 */

#define ITERS 2
#define SEM_NAME "/semaphore-demo-rms46"

/* ATTN:
   Replace the "rms46" part in SEM_NAME with your userid!
   "Dead semaphores" are lingering in folder "/dev/shm/".
   If you are the owner, you can delete "dead semaphores" manually.
 * *************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#define  DELAY 10000000

int main(void) {
    pid_t mypid = getpid();
    sem_t *semaphore = sem_open(SEM_NAME, O_RDWR);

    if (semaphore == SEM_FAILED) {
        perror("sem_open(3) failed");
        exit(EXIT_FAILURE);
    }
    printf("Child  PID[%d] is UP!\n", mypid);
    for (int ii = 0; ii < ITERS; ii++) {
        sleep(1);
        sem_wait(semaphore);
        printf("Child  PID[%d] is inside  the Critical Section\n", mypid);
        sem_post(semaphore);
        printf("Child  PID[%d] is outside the Critical Section\n", mypid);
    }
    if (sem_close(semaphore) < 0)
        perror("sem_close(3) failed");
    return 0;
}

/*
 * TAKE NOTE (RMS)
 * "21-child" is executed by "20-parent".
 */

