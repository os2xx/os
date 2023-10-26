/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2016-2 (midterm)
 * REV02: Thu 26 Oct 2023 20:00
 * REV01: Sun 23 Feb 2020 16:00
 * START: Fri 01 Jan 2016 00:00
 * Assume (&ptrchr is 0x7FFFEEDDCCBB, order of bytes: little-endian) */
#define LINES  3
#include <stdio.h>
void printeq(int lines) {
   while (lines-- > 0 ) printf("= = ");
   printf("\n");
}
void main(void) {
   int             ii;
   unsigned char   dummy  = 'a';
   unsigned char*  ptrchr = &dummy;

   printeq(LINES);
   printf(" dummy:  %c\n", dummy);
   printf("*ptrchr: %c\n", *ptrchr);
   printeq(LINES);
   printf("%p\n", &ptrchr);
   printeq(LINES);
   ptrchr = (char*) &ptrchr;
   for (ii=0; ii<6; ii++) {
      printf("%X ", *ptrchr);
      ptrchr++;
   }
   putchar('\n');
   printeq(LINES);
}

