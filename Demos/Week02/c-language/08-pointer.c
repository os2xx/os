/*
 * Copyright (C) 2019-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: An introduction to pointers.
 * REV02: Thu 26 Oct 2023 19:00
 * REV01: Fri 07 Feb 2020 01:00
 * START: Tue 26 Feb 2019 12:00
 */

#include <stdio.h>

void main (void) {
   char    cca='a';
   printf ("Print   cca: %c\n", cca);
   char    ccb='b';
   printf ("Print   ccb: %c\n", ccb);
   char*   ptr=&cca;
   printf ("Print  *ptr: %c\n", *ptr);
   ptr=&ccb;
   printf ("Print  *ptr: %c\n", *ptr);
   char    array[]="ABCDEF";
   printf ("Print array: %s\n", array);
   ptr=array;
   printf ("Print  *ptr: %c\n", *ptr);
   ptr=&array[0];
   printf ("Print  *ptr: %c\n", *ptr);
   ptr=&array[1];
   printf ("Print  *ptr: %c\n", *ptr);
   ptr=ptr+1;
   printf ("Print  *ptr: %c\n", *ptr);
   ptr++;
   printf ("Print  *ptr: %c\n", *ptr);
}

