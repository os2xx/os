/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: UTS 2017-2 (midterm)
 * REV05: Thu 26 Oct 2023 19:00
 * REV04: Fri 07 Feb 2020 01:00
 * REV03: Thu 17 Jan 2019 13:00
 * REV02: Tue 28 Aug 2018 13:00
 * START: Mon 16 Oct 2017 21:00
 */

#include <stdio.h>

char globalChar='a';

char* getGlobal(void) {
   char* charPTR=&globalChar;
   printf("getGlobal1 %c\n", globalChar);
   *charPTR='b';
   printf("getGlobal2 %c\n", *charPTR);
   return charPTR;
}

void main (void) {
   char localChar='c';
   printf("==== main1 %c\n", localChar);
   localChar=*getGlobal();
   printf("==== main2 %c\n", localChar);
}

/*
 * TAKE NOTE (ZA)
 * Line 25: mengambil local char pada fungsi yaitu c
 * Line 26: memanggil fungsi getGlobal()
 * Line 17: mengambil global char yaitu a
 * Line 19: mengganti chartPTR dari a menjadi b
 * Line 27: menggambil local char terakhir yaitu b
 */

