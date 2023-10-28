/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 * REV08: Sat 28 Oct 2023 13:00
 * REV07: Wed 25 Mar 2020 16:00
 * REV06: Tue 26 Nov 2019 11:00
 * REV02: Fri 18 May 2018 13:00
 * REV01: Sun 05 Jun 2016 00:00
 * START: Thu 01 Jan 2015 00:00

# INFO: UAS 2016-1 (final term)
# INFO:                   To run:   ./70-161

 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE "70-os161-demo.txt"

char *string = "ABCD\n";
void main(void) {
   int fileDescriptor;
   printf("See also file %s\n", FILE);
   close(STDOUT_FILENO);
   fileDescriptor = open (FILE, O_RDWR|O_CREAT|O_TRUNC, 0644);
   printf ( "%s", string);
   write(fileDescriptor, string, strlen(string));
}

