/*
 * Copyright (C) 2021-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# INFO: MYADDDRESSES
 * REV04: Sat 28 Oct 2023 18:00
 * REV03: Mon 03 Oct 2022 11:00
 * REV02: Wed 16 Mar 2022 14:00
 * REV01: Sun 03 Oct 2021 18:00
 * START: Sat 03 Apr 2021 06:00
 */

#define ArraySize   1024*1024*1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

typedef char*           String;
typedef int*            IntPtr;
typedef unsigned long   UL;
typedef void*           AnyAddrPtr;
typedef struct sysinfo  SYSINFO;

int pcounter=1;
void printMyAddress (AnyAddrPtr address, String message) {
    printf("ZCZC ADDR %2.2d %#16.16lX %s\n", pcounter++, (UL) address, message);
}

int main(void) {
    SYSINFO guestInfo;
    int     localdummy=0;

    sysinfo(&guestInfo);
    printf("ZCZC RAM     %5lu MB\n",  guestInfo.totalram/1024/1024);
    printf("ZCZC FREE    %5lu MB\n",  guestInfo.freeram/1024/1024);
    printf("ZCZC BUFFER  %5lu MB\n",  guestInfo.bufferram/1024/1024);
    printf("ZCZC SWAP    %5lu MB\n",  guestInfo.totalswap/1024/1024);
    printf("ZCZC FREESW  %5lu MB\n",  guestInfo.freeswap/1024/1024);
    IntPtr  intArray=malloc((ArraySize+1) * sizeof(int));
    sysinfo(&guestInfo);
    printf("ZCZC FREE1   %5lu MB\n",  guestInfo.freeram/1024/1024);
    printf("ZCZC FREESW1 %5lu MB\n",  guestInfo.freeswap/1024/1024);
    for (int ii=0; ii<ArraySize; ii++) intArray[ii]=255;
    sysinfo(&guestInfo);
    printf("ZCZC FREE2   %5lu MB\n",  guestInfo.freeram/1024/1024);
    printf("ZCZC FREESW2 %5lu MB\n",  guestInfo.freeswap/1024/1024);

    printMyAddress( printMyAddress, "printMyAddress()");
    printMyAddress( main,           "main()");
    printMyAddress(&pcounter,      "&pcounter");
    printMyAddress( intArray,       "intArray");
    printMyAddress( printf,         "printf()");
    printMyAddress(&intArray,      "&intArray");
    printMyAddress(&localdummy,    "&localdummy");
    printMyAddress(&guestInfo,     "&guestInfo");

    sleep(1);
}

