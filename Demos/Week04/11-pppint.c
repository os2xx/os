/*
 * Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
# INFO: TBA
 * REV03: Thu 26 Oct 2023 20:00
 * REV02: Sun 23 Feb 2020 16:00
 * REV01: Thu 04 Oct 2018 20:00
 * START: Thu 04 Oct 2018 10:00
 *
 */


#include <stdio.h>
unsigned int     int0=0x41424344;
unsigned int     int1=0x45464748;
unsigned int     int2=0x61626364;
unsigned char    terminal=0;
unsigned int*    pt1_int;
unsigned char*   pt1_char;

void main(void) {
   int ii;
   printf("ADDRESSES of int0=%p, int1=%p, int2=%p\n", 
           &int0, &int1, &int2);
   printf("VALUES    of int0=%X, int1=%X, int2=%X\n",  
           int0,  int1,  int2);
   pt1_int=&int0;
   printf("The ADDRESS of pt1_int is  %p\n", &pt1_int);
   for (ii=0; ii<3; ii++, pt1_int++) {
      printf("pt1_int=%p, *pt1_int=%X\n", pt1_int, *pt1_int);
   }
   printf("The ADDRESS of pt1_char is %p, terminal is %p\n", &pt1_char, &terminal);
   pt1_char = (char *) &int0;
   printf("*pt1_char   =%c\n",  *pt1_char);
   printf(" pt1_char[5]=%c\n", pt1_char[5]);
   printf(" pt1_char   =%s\n",   pt1_char);
   pt1_char=&terminal;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char--;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char--;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
   pt1_char -= 5;
   printf("*pt1_char=%2.2X (%p)\n", *pt1_char, pt1_char);
}


