/*
 * Copyright (C) 2016-2021 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV07: Wed 29 Sep 2021 08:12:48 WIB
 * REV06: Tue 23 Mar 10:14:44 WIB 2021
 * REV05: Sun Feb 23 16:59:31 WIB 2020
 * REV04: Tue Aug 28 18:40:36 WIB 2018
 * REV03: Tue Oct  3 20:30:14 WIB 2017
 * START: Tue Sep 20 17:00:52 WIB 2016
 */

#include <stdio.h>

/* Global Variables */
unsigned char   varchr0='a';
unsigned char   varchr1='b';
unsigned char   varchr2='c';
unsigned char   varchr3='d';
unsigned char*  ptrchr0=&varchr0;
unsigned char*  ptrchr1=&varchr1;
unsigned char*  ptrchr2=&varchr2;
unsigned char*  ptrchr3=&varchr3;
unsigned char** ptrptr0=&ptrchr0;
unsigned char** ptrptr1=&ptrchr1;
unsigned char** ptrptr2=&ptrchr2;
unsigned char** ptrptr3=&ptrchr3;

void main(void) {
   printf("Address &ptrptr0 = %#16.16lX\n",  &ptrptr0);
   printf("Value    ptrptr0 = %#16.16lX\n",   ptrptr0);
   printf("Address &ptrchr0 = %#16.16lX\n",  &ptrchr0);
   printf("Pointer *ptrptr0 = %#16.16lX\n",  *ptrptr0);
   printf("Value    ptrchr0 = %#16.16lX\n",   ptrchr0);
   printf("Address &varchr0 = %#16.16lX\n",  &varchr0);
   printf("PtrPtr **ptrptr0 = %18c\n",      **ptrptr0);
   printf("Pointer *ptrchr0 = %18c\n",       *ptrchr0);
   printf("Value    varchr0 = %18c\n\n",      varchr0);

   printf("Address &ptrptr1 = %#16.16lX\n",  &ptrptr1);
   printf("Value    ptrptr1 = %#16.16lX\n",   ptrptr1);
   printf("Address &ptrchr1 = %#16.16lX\n",  &ptrchr1);
   printf("Pointer *ptrptr1 = %#16.16lX\n",  *ptrptr1);
   printf("Value    ptrchr1 = %#16.16lX\n",   ptrchr1);
   printf("Address &varchr1 = %#16.16lX\n",  &varchr1);
   printf("PtrPtr **ptrptr1 = %18c\n",      **ptrptr1);
   printf("Pointer *ptrchr1 = %18c\n",       *ptrchr1);
   printf("Value    varchr1 = %18c\n\n",      varchr1);

   printf("Address &ptrptr2 = %#16.16lX\n",  &ptrptr2);
   printf("Value    ptrptr2 = %#16.16lX\n",   ptrptr2);
   printf("Address &ptrchr2 = %#16.16lX\n",  &ptrchr2);
   printf("Pointer *ptrptr2 = %#16.16lX\n",  *ptrptr2);
   printf("Value    ptrchr2 = %#16.16lX\n",   ptrchr2);
   printf("Address &varchr2 = %#16.16lX\n",  &varchr2);
   printf("PtrPtr **ptrptr2 = %18c\n",      **ptrptr2);
   printf("Pointer *ptrchr2 = %18c\n",       *ptrchr2);
   printf("Value    varchr2 = %18c\n\n",      varchr2);

   printf("Address &ptrptr3 = %#16.16lX\n",  &ptrptr3);
   printf("Value    ptrptr3 = %#16.16lX\n",   ptrptr3);
   printf("Address &ptrchr3 = %#16.16lX\n",  &ptrchr3);
   printf("Pointer *ptrptr3 = %#16.16lX\n",  *ptrptr3);
   printf("Value    ptrchr3 = %#16.16lX\n",   ptrchr3);
   printf("Address &varchr3 = %#16.16lX\n",  &varchr3);
   printf("PtrPtr **ptrptr3 = %18c\n",      **ptrptr3);
   printf("Pointer *ptrchr3 = %18c\n",       *ptrchr3);
   printf("Value    varchr3 = %18c\n\n",      varchr3);
}

/*
Address &ptrptr0 = 0X0000556677889958
Value    ptrptr0 = 0X0000556677889938
Address &ptrchr0 = 0X0000556677889938
Pointer *ptrptr0 = 0X0000556677889930
Value    ptrchr0 = 0X0000556677889930
Address &varchr0 = 0X0000556677889930
PtrPtr **ptrptr0 =                  a
Pointer *ptrchr0 =                  a
Value    varchr0 =                  a

Address &ptrptr1 = 0X0000556677889960
Value    ptrptr1 = 0X0000556677889940
Address &ptrchr1 = 0X0000556677889940
Pointer *ptrptr1 = 0X0000556677889931
Value    ptrchr1 = 0X0000556677889931
Address &varchr1 = 0X0000556677889931
PtrPtr **ptrptr1 =                  b
Pointer *ptrchr1 =                  b
Value    varchr1 =                  b

Address &ptrptr2 = 0X0000556677889968
Value    ptrptr2 = 0X0000556677889948
Address &ptrchr2 = 0X0000556677889948
Pointer *ptrptr2 = 0X0000556677889932
Value    ptrchr2 = 0X0000556677889932
Address &varchr2 = 0X0000556677889932
PtrPtr **ptrptr2 =                  c
Pointer *ptrchr2 =                  c
Value    varchr2 =                  c

Address &ptrptr3 = 0X0000556677889970
Value    ptrptr3 = 0X0000556677889950
Address &ptrchr3 = 0X0000556677889950
Pointer *ptrptr3 = 0X0000556677889933
Value    ptrchr3 = 0X0000556677889933
Address &varchr3 = 0X0000556677889933
PtrPtr **ptrptr3 =                  d
Pointer *ptrchr3 =                  d
Value    varchr3 =                  d

                      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0000 5566 7788 9930  61 62 63 64  -  -  -  - 30 99 88 77 66 55 00 00
0000 5566 7788 9940  31 99 88 77 66 55 00 00 32 99 88 77 66 55 00 00
0000 5566 7788 9950  33 99 88 77 66 55 00 00 38 99 88 77 66 55 00 00
0000 5566 7788 9960  40 99 88 77 66 55 00 00 48 99 88 77 66 55 00 00
0000 5566 7788 9970  50 99 88 77 66 55 00 00  -  -  -  -  -  -  -  -

*/

