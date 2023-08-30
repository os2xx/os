/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV09: Wed 29 Sep 2021 08:10:06 WIB
 * REV08: Tue 28 Sep 2021 21:24:42 WIB
 * REV07: Fri 02 Apr 07:37:07 WIB 2021
 * REV06: Tue 23 Mar 10:01:44 WIB 2021
 * REV05: Sun 23 Feb 16:59:31 WIB 2020
 * START: Tue 20 Sep 17:00:52 WIB 2016
 */

#include <stdio.h>

/* Global Variables */
unsigned char  varchr0='a';
unsigned char  varchr1='b';
unsigned char  varchr2='c';
unsigned char  varchr3='d';
unsigned char* ptrchr0=&varchr0;
unsigned char* ptrchr1=&varchr1;
unsigned char* ptrchr2=&varchr2;
unsigned char* ptrchr3=&varchr3;

void main(void) {
   printf("Address &ptrchr0 = %#16.16lX\n",  &ptrchr0);
   printf("Value    ptrchr0 = %#16.16lX\n",   ptrchr0);
   printf("Address &varchr0 = %#16.16lX\n",  &varchr0);
   printf("Pointer *ptrchr0 = %18c\n",       *ptrchr0);
   printf("Value    varchr0 = %18c\n\n",      varchr0);

   printf("Address &ptrchr1 = %#16.16lX\n",  &ptrchr1);
   printf("Value    ptrchr1 = %#16.16lX\n",   ptrchr1);
   printf("Address &varchr1 = %#16.16lX\n",  &varchr1);
   printf("Pointer *ptrchr1 = %18c\n",       *ptrchr1);
   printf("Value    varchr1 = %18c\n\n",      varchr1);

   printf("Address &ptrchr2 = %#16.16lX\n",  &ptrchr2);
   printf("Value    ptrchr2 = %#16.16lX\n",   ptrchr2);
   printf("Address &varchr2 = %#16.16lX\n",  &varchr2);
   printf("Pointer *ptrchr2 = %18c\n",       *ptrchr2);
   printf("Value    varchr2 = %18c\n\n",      varchr2);

   printf("Address &ptrchr3 = %#16.16lX\n",  &ptrchr3);
   printf("Value    ptrchr3 = %#16.16lX\n",   ptrchr3);
   printf("Address &varchr3 = %#16.16lX\n",  &varchr3);
   printf("Pointer *ptrchr3 = %18c\n",       *ptrchr3);
   printf("Value    varchr3 = %18c\n\n",      varchr3);
}

/*
Address &ptrchr0 = 0X0000556677889938
Value    ptrchr0 = 0X0000556677889930
Address &varchr0 = 0X0000556677889930
Pointer *ptrchr0 =                  a
Value    varchr0 =                  a

Address &ptrchr1 = 0X0000556677889940
Value    ptrchr1 = 0X0000556677889931
Address &varchr1 = 0X0000556677889931
Pointer *ptrchr1 =                  b
Value    varchr1 =                  b

Address &ptrchr2 = 0X0000556677889948
Value    ptrchr2 = 0X0000556677889932
Address &varchr2 = 0X0000556677889932
Pointer *ptrchr2 =                  c
Value    varchr2 =                  c

Address &ptrchr3 = 0X0000556677889950
Value    ptrchr3 = 0X0000556677889933
Address &varchr3 = 0X0000556677889933
Pointer *ptrchr3 =                  d
Value    varchr3 =                  d

                      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0000 5566 7788 9930  61 62 63 64  -  -  -  - 30 99 88 77 66 55 00 00
0000 5566 7788 9940  31 99 88 77 66 55 00 00 32 99 88 77 66 55 00 00
0000 5566 7788 9950  33 99 88 77 66 55 00 00  -  -  -  -  -  -  -  -

*/

