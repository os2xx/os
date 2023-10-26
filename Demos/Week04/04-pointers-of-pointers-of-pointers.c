/*
 * Copyright (C) 2016-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: TBA
 * REV08: Thu 26 Oct 2023 20:00
 * REV07: Tue 28 Sep 2021 17:00
 * REV05: Tue 01 Oct 2019 11:00
 * REV04: Tue 28 Aug 2018 18:00
 * REV03: Tue 03 Oct 2017 20:00
 * START: Tue 20 Sep 2016 17:00
 */

#include <stdio.h>

/* Global Variables */
unsigned char   varchr0='a';
unsigned char*  ptrchr0=&varchr0;
unsigned char** ptrptr0=&ptrchr0;
unsigned char*** ppptr0=&ptrptr0;

void main(void) {
   printf("Address  &ppptr0 = %#16.16lX\n",   &ppptr0);
   printf("Value     ppptr0 = %#16.16lX\n",    ppptr0);
   printf("Address &ptrptr0 = %#16.16lX\n",  &ptrptr0);
   printf("Pointer  *ppptr0 = %#16.16lX\n",   *ppptr0);
   printf("Value    ptrptr0 = %#16.16lX\n",   ptrptr0);
   printf("Address &ptrchr0 = %#16.16lX\n",  &ptrchr0);
   printf("PtrPtr  **ppptr0 = %#16.16lX\n",  **ppptr0);
   printf("Pointer *ptrptr0 = %#16.16lX\n",  *ptrptr0);
   printf("Value    ptrchr0 = %#16.16lX\n",   ptrchr0);
   printf("Address &varchr0 = %#16.16lX\n",  &varchr0);
   printf("PPPtr  ***ppptr0 = %18c\n",      ***ppptr0);
   printf("PtrPtr **ptrptr0 = %18c\n",      **ptrptr0);
   printf("Pointer *ptrchr0 = %18c\n",       *ptrchr0);
   printf("Value    varchr0 = %18c\n\n",      varchr0);

}

/*
Address  &ppptr0 = 0X0000556677889948
Value     ppptr0 = 0X0000556677889940
Address &ptrptr0 = 0X0000556677889940
Pointer  *ppptr0 = 0X0000556677889938
Value    ptrptr0 = 0X0000556677889938
Address &ptrchr0 = 0X0000556677889938
PtrPtr  **ppptr0 = 0X0000556677889930
Pointer *ptrptr0 = 0X0000556677889930
Value    ptrchr0 = 0X0000556677889930
Address &varchr0 = 0X0000556677889930
PPPtr  ***ppptr0 =                  a
PtrPtr **ptrptr0 =                  a
Pointer *ptrchr0 =                  a
Value    varchr0 =                  a

                      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
0000 5566 7788 9930  61  -  -  -  -  -  -  - 30 99 88 77 66 55 00 00 
0000 5566 7788 9940  38 99 88 77 66 55 00 00 40 99 88 77 66 55 00 00 
*/
