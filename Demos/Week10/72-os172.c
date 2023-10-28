/*
 * Copyright (C) 2017-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV06: Sat 28 Oct 2023 13:00
 * REV05: Wed 25 Mar 2020 16:00
 * REV04: Tue 26 Nov 2019 11:00
 * REV02: Fri 18 May 2018 14:00
 * START: Wed 18 Oct 2017 18:00

# INFO: UAS 2017-2 (final term)
# INFO:                   To run:   ./72-172

 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define FILE "72-os172-demo.txt"

void main(void) {
   int fd1, fd2;
   printf("See also file %s\n", FILE);
   fd1 = open (FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
   fd2 = dup(fd1);
   write (fd1, "0123456789\n", 5);
   write (fd2, "abcdefghij\n", 5);
   close(fd1);
   close(fd2);
}
