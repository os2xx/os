/*
 * Copyright (C) 2021-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06: Fri 27 Oct 2023 07:00
 * REV05: Tue 30 Mar 2021 14:00
 * REV04: Tue 30 Mar 2021 10:00
 * REV03: Tue 30 Mar 2021 08:00
 * START: Mon 22 Mar 2021 16:00
 *
# INFO: chktoken(TOKEN) function
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

void getTimeStamp(uChrPtr timeStamp) {
    time_t tt    =  time(NULL);
    struct tm tm = *localtime(&tt);
    sprintf(timeStamp, "%2.2d%2.2d", tm.tm_min, tm.tm_sec);
}

void     chktoken (uChrPtr token) {
    uChr    input [MAXINPUT];
    uChr    output[MAXOUTPUT];
    uChr    timeStamp[] = "MMSS";
    uChrPtr user        = getenv("USER");
    getTimeStamp(timeStamp);
    int     len   = strlen(timeStamp);
    strcpy(input,timeStamp);
    strcpy(input+len,user);
    len          += strlen(user);
    strcpy(input+len,token);
    len          += strlen(token);
    mySHA1(input,   output);
    printf("%s %s-%s\n", user, timeStamp, output);
}

