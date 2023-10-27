# REV04: Fri 27 Oct 2023 07:00
# REV03: Fri 02 Apr 2021 07:00
# REV02: Thu 25 Mar 2021 18:00
# REV01: Sun 23 Feb 2020 18:00
# START: Mon 03 Oct 2016 09:00

# INFO: With this "Makefile", just run:
# INFO:                     make

CC=gcc

EXECS= \
	12-memory


all:  $(EXECS)


12-memory: 12-memory.c 13-chktoken.c
	$(CC) -std=gnu18 12-memory.c 13-chktoken.c -o 12-memory -Xlinker  \
		-Map=12-memory.map

clean:
	rm -f ${EXECS} 
	rm -f *.map
 
.phony: all clean

