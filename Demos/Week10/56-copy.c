/*
 * Copyright (C) 2015-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * TAKE NOTE (MA)
 * Program ini akan mengcopy isi dari suatu file 
 * ke file lain yang sudah ada atau belum ada
 *
 * Argumen argc dan argv dari main digunakan 
 * sebagai cara untuk mengirim argumen ke program
 * argc adalah jumlah argumen,
 * argv adalah list argumennya, 
 * yang untuk list ke 0 merupakan nama filenya.
 *
 * Jadi, program ini butuh 2 argumen tambahan saat dijalankan,
 * yang pertama adalah file yang isinya mau dicopy
 * yang kedua adalah file hasil copy-annya
 * yang jika file kedua namanya sudah ada maka akan direplace isinya
 *
 * Contohnya: ./56-copy test.txt test2.txt 
 * (test.txt harus ada dibuat terlebih dahulu dahulu atau akan error)
 *
 * REV05: Sat 28 Oct 2023 12:00
 * REV04: Tue 26 Nov 2019 11:00
 * REV03: Wed 29 Aug 2018 20:00
 * REV01: Mon 02 Oct 2017 16:00
 * START: Sat 25 Apr 2015 00:00
 * USE "cmp file1 file2"
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define  BUF_SIZE 16

void main(int argc, char* argv[])
{
   int          fdread, fdwrite;
   unsigned int total_bytes = 0;
   ssize_t      nbytes_read, nbytes_write;
   char buf[BUF_SIZE];
   if (argc != 3) {
      printf("Usage: %s source destination\n",
      argv[0]);
      exit(1);
   }
   fdread = open(argv[1], O_RDONLY);
   if (fdread < 0) {
      perror("Failed to open source file");
      exit(1);
   }
   fdwrite = creat(argv[2], S_IRWXU);
   if (fdwrite < 0) {
      perror("Failed to open destination file");
      exit(1);
   }
   do {
      nbytes_read = read(fdread, buf, BUF_SIZE);
      if (nbytes_read < 0) {
         perror("Failed to read from file");
         exit(1);
      }
      nbytes_write = write(fdwrite, buf, nbytes_read);
      if (nbytes_write < 0) {
         perror("Failed to write to file");
         exit(1);
      }
   } while (nbytes_read > 0);
   close(fdread);
   close(fdwrite);
   exit(0);
}
