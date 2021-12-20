/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: Global Variables and Addresses
 * REV07: Fri 02 Apr 07:42:51 WIB 2021
 * REV06: Tue 23 Mar 09:30:48 WIB 2021
 * REV05: Sun 23 Feb 16:59:31 WIB 2020
 * REV04: Tue 28 Aug 18:40:36 WIB 2018
 * REV03: Tue 03 Oct 18:58:13 WIB 2017
 * START: Tue 20 Sep 17:00:52 WIB 2016
 */

#include <stdio.h>
#define HEAD1 "VARIABLE + VALUE +CHR+ ++++ ADDRESS  ++++\n"

/* Global Variables in Data Segment */
unsigned char varchr0='a';
unsigned char varchr1='b';
unsigned char varchr2='c';
unsigned char varchr3='d';
unsigned char varchr4='e';
unsigned char varchr5='f';
unsigned char varchr6='g';
unsigned char varchr7='h';

void main(void) {
   printf(HEAD1);
   printf("varchr0  =  %#4X = %c   %#16.16lX\n", varchr0, varchr0, &varchr0);
   printf("varchr1  =  %#4X = %c   %#16.16lX\n", varchr1, varchr1, &varchr1);
   printf("varchr2  =  %#4X = %c   %#16.16lX\n", varchr2, varchr2, &varchr2);
   printf("varchr3  =  %#4X = %c   %#16.16lX\n", varchr3, varchr3, &varchr3);
   printf("varchr4  =  %#4X = %c   %#16.16lX\n", varchr4, varchr4, &varchr4);
   printf("varchr5  =  %#4X = %c   %#16.16lX\n", varchr5, varchr5, &varchr5);
   printf("varchr6  =  %#4X = %c   %#16.16lX\n", varchr6, varchr6, &varchr6);
   printf("varchr7  =  %#4X = %c   %#16.16lX\n", varchr7, varchr7, &varchr7);
}

/*
VARIABLE + VALUE +CHR+ ++++ ADDRESS  ++++
varchr0  =  0X61 = a   0X0000556677889938
varchr1  =  0X62 = b   0X0000556677889939
varchr2  =  0X63 = c   0X000055667788993A
varchr3  =  0X64 = d   0X000055667788993B
varchr4  =  0X65 = e   0X000055667788993C
varchr5  =  0X66 = f   0X000055667788993D
varchr6  =  0X67 = g   0X000055667788993E
varchr7  =  0X68 = h   0X000055667788993F

                      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0000 5566 7788 9930   -  -  -  -  -  -  -  - 61 62 63 64 65 66 67 68
*/

