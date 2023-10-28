/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * TAKE NOTE (MA)
 * Program ini akan membuat file baru dengan isi
 * buf1 pada 8 char pertama, dan buf2 pada 8 char terakhir
 *
 * Line 31 akan membuat program menulis 8 char 
 * dari variabel char buf1 ke file yang didefine pada Line 19
 *
 * Line 35 akan membuat offset menjadi 32,
 * yang maksudnya adalah pointernya lompat ke huruf ke 32
 * Sehingga ketika menulis lg, akan dimulai pada huruf ke 33
 *
 * REV07: Sat 28 Oct 2023 12:00
 * REV06: Tue 26 Nov 2019 11:00
 * REV05: Wed 29 Aug 2018 20:00
 * REV04: Wed 18 Oct 2017 17:00
 * REV02: Thu 09 Mar 2017 21:00
 * START: Sat 25 Apr 2015 00:00
 * USE "hexdump FILE1"
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define  FILE6   "demo-file6.txt"

char buf1[] = "abcdefgh";
char buf2[] = "ABCDEFGH";

void main(void) {
   int fd;
   fd = creat(FILE6, 0644);
   if (fd < 0) {
      perror("creat error");
      exit(1);
   }
   if (write(fd, buf1, 8) != 8) {
      perror("buf1 write error");
      exit(1);
   } /* offset now = 8 */
   if (lseek(fd, 32, SEEK_SET) == -1) {
      perror("lseek error");
      exit(1);
   } /* offset now = 32 */
   if (write(fd, buf2, 8) != 8) {
      perror("buf2 write error");
      exit(1);
   } /* offset now = 40 */
   close(fd);
   printf("Run: hexdump -c %s\n", FILE6);
}
