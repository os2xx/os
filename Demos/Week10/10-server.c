/*
 * Copyright (C) 2007-2023 BinKadal, Sdn. Bhd.
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03: Sat 28 Oct 2023 12:00
 * REV02: Sun 03 May 2020 07:00
 * REV01: Wed 29 Aug 2018 20:00
 * START: Mon 01 Jan 2007 00:00
 */

char pesan[]="[FROM SERVER] ACK MESSAGE...\n";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
typedef struct sockaddr    sockad;
typedef struct sockaddr_in sockadin;
typedef struct hostent     shostent;

void error(char *msg){
   perror(msg);
   exit(0);
}

int main(int argc, char *argv[]) {
   char     buffer[256];
   int      clilen, newsockfd, nn, portno, sockfd;
   sockadin serv_addr, cli_addr;

   if (argc < 2) {
      fprintf(stderr, "ERROR, no port provided\n");
      exit(1);
   }
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0)
      error("ERROR opening socket");
   int enable = 1;
   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
      error("setsockopt(SO_REUSEADDR) failed");
   memset(&serv_addr, 0, sizeof(serv_addr));
   portno = atoi(argv[1]);
   serv_addr.sin_family      = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port        = htons(portno);
   if (bind(sockfd, (sockad*) &serv_addr, sizeof(serv_addr))< 0)
      error("ERROR on binding");
   listen(sockfd, 5);
   clilen = sizeof(cli_addr);
   newsockfd=accept(sockfd,(sockad*)&cli_addr,(socklen_t*)&clilen);
   if (newsockfd < 0)
      error("ERROR on accept");
   memset(buffer, 0, 256);
   nn = read(newsockfd,buffer,255);
   if (nn < 0)
      error("ERROR reading from socket");
   printf("[FROM CLIENT]:\n %s\n",buffer);
   nn = write(newsockfd, pesan, sizeof(pesan));
   if (nn < 0)
      error("ERROR writing to socket");
   return 0;
}
