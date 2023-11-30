/*
 Copyright (C) 2023-2023 BinKadal, Sdn. Bhd.
 This program is free script/software. This 
 program is distributed in the hope that it
 will be useful,  but WITHOUT ANY WARRANTY; 
 without  even   the  implied  warranty  of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.
 REV01: Thu 30 Nov 2023 07:00
 START: Sat 25 Apr 2015 00:00
 */

typedef char* STRING;
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILE1 "99-extra-demo.txt"
#define NEWFD 10

STRING str1= "This is STRING1\n";
STRING str2= "This is STRING2\n";
STRING str3= "This is STRING3\n";
STRING str4= "This is STRING4\n";

void main(void) {
   printf("**** Please check file %s *****\n", FILE1);
   close(STDOUT_FILENO);
   int fd1 = open (FILE1, O_RDWR | O_CREAT | O_TRUNC, 0644);
   close(STDERR_FILENO);
   int fd2 = dup2(fd1, NEWFD);

   printf("File Descriptors --- fd1 = %d, fd2 = %d\n", fd1, fd2);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
   write(STDOUT_FILENO, str3, strlen(str3));
   write(NEWFD, str4, strlen(str4));
}

