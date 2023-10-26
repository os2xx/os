/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: More printf() examples.
 * REV06: Thu 26 Oct 2023 19:00
 * REV05: Fri Feb  7 2020 01:00
 * REV04: Fri Jan 25 2019 17:00
 * REV02: Tue Aug 28 2018 13:00
 * START: Thu Sep 15 2016 11:00
 */

#include <stdio.h>

void main (void) {
   short             sii    = 1;
   unsigned short    usii   = sii * -1;
   printf("short     %hd |||| unsigned short     %hu\n", sii, usii);

   int               ii     = 1;
   unsigned          uii    = ii * -1;
   printf("int       %d |||| unsigned           %u\n", ii, uii);

   long              lii    = 1;
   unsigned long     ulii   = lii * -1;
   printf("long      %ld |||| unsigned long      %lu (%#lX)\n", lii, ulii, ulii);

   long long         llii   = 1;
   unsigned long long ullii = llii * -1;
   printf("long long %lld |||| unsigned long long %llu (%#llX)\n", llii, ullii, ullii);

   float            ff    = 123456789.12345678;
   printf("float       %f (%e)\n", ff, ff);
   double            dff  = 123456789.12345678;
   printf("double      %lf (%le)\n", dff, dff);
   long double       ldff = 123456789.12345678;
   printf("long double %Lf (%Le)\n", ldff, ldff);

   char        ch='A';
   unsigned char uch = (unsigned char) -191;
   printf("char %c (%d) |||| unsigned char       %c (%u)\n", ch, ch, uch, uch);

#define STRING "123456789ABCDEF\n"

   char  dd[]=STRING;
   long  size=sizeof(STRING);
   printf(STRING);
   printf("One  more time:\n%sSIZE=%ld\n", dd, size);
   printf("dd[]= %c%c%c ... %c\n", dd[0], 
           dd[1], dd[2], dd[size-3]);
}

