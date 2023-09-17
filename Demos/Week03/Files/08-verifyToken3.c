/*
 * Copyright (C) 2021-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04: Sun 17 Sep 2023 09:00
 * REV03: Tue 30 Mar 2021 11:00
 * START: Mon 22 Mar 2021 16:00
 *
# INFO: 08-verifyToken TOKEN CHKTOKEN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define  MAXINPUT   256
#define  MAXCMD     MAXINPUT
#define  MAXOUTPUT  MAXINPUT
#define  RESULT     4

typedef           char  Chr;
typedef           char* ChrPtr;
typedef  unsigned char  uChr;
typedef  unsigned char* uChrPtr;

#define CMDSTRING "echo %s | sha1sum | cut -c1-4 | tr '[:lower:]' '[:upper:]' "
void mySHA1(uChrPtr input, uChrPtr output) {
    Chr  cmd[MAXCMD];
    sprintf(cmd, CMDSTRING, input);
    FILE* filePtr = popen(cmd, "r");
    fgets(output, RESULT+1, filePtr);
    output[RESULT]=0;
    pclose(filePtr);
}

int main(int argc, ChrPtr argv[]) {
    uChr    input[MAXINPUT];
    uChr    output[MAXOUTPUT];
    if (argc < 4) {
        printf("Usage: verifyToken TOKEN USER RESULT\n");
        // printf("Or:    verifyToken TOKEN USER RESULT trueFalseMode\n");
        return 0;
    }
    uChrPtr token   = argv[1];
    uChrPtr user    = argv[2];
    uChrPtr result  = argv[3];
    strncpy (input,result,4);
    strcpy  (input+4,user);
    int len = 4 + strlen(user);
    strcpy  (input+len,token);

    mySHA1(input,   output);

    strcpy (input+4,output);
    uChrPtr tmpptr  = result+4;
    while (*(tmpptr)=*(tmpptr+1)) tmpptr++;
    if (strcmp(input, result) == 0 ) printf("Verified\n");
    else printf("Error\n");

    return 0;
}

