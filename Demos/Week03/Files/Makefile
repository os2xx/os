#!/bin/bash
# REV21: Sun 17 Sep 2023 08:00
# REV20: Fri  2 Apr 2021 07:00
# REV19: Tue 30 Mar 2021 10:00
# REV17: Sun 23 Feb 2020 16:00
# REV16: Mon 28 Jan 2019 19:00
# START: Tue 13 Sep 2016 11:00

# Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
# This program is free script/software. This program is distributed in the hope 
# that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# INFO: With this "Makefile", just run:
# INFO:                     make

CC            = gcc
CPP           = cpp
CFLAGS        = -std=gnu18
LDFLAGS       = 
CPPFLAGS      =
DEPFLAGS      = -MM -MT $(@:.d=.o) 
OUTPUT_OPTION = -o $@
COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
SRCS          = $(wildcard *.c)
OBJ           = $(SRCS:.c=.o)
DEP           = $(OBJ:.o=.d)
PROGS         = $(SRCS:.c=  )

P01=01-open-close
P02=02-file-pointer
P03=03-fprintf
P04=04-dprintf
P05=05-sprintf
P06=06-printf
P07=07-chktoken3
P08=08-verifyToken3

EXECS= \
        $(P01) \
        $(P02) \
        $(P03) \
        $(P04) \
        $(P05) \
        $(P06) \
        $(P07) \
        $(P08) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \


MODE644=\
	demo-file4.txt \

all:  $(EXECS) demo-file4.txt

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo: demo-file4.txt
demo-file4.txt:
	@echo "Line 1: Blah Blah Blah 1" >  demo-file4.txt
	@echo "Line 2: Blah Blah Blah 2" >> demo-file4.txt
	@echo "Line 3: Blah Blah Blah 3" >> demo-file4.txt
	@chmod 644 $(MODE644)

.phony: clean demo

