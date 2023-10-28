# REV20: Sat 28 Oct 2023 18:00
# REV19: Wed 13 Sep 2023 05:00
# REV10: Mon 12 Oct 2020 11:00
# REV08: Tue 10 Dec 2019 10:00
# REV04: Tue 25 Sep 2018 12:00
# START: Tue 13 Sep 2016 11:00

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

P00=00-hallo
P01=01-printf-int
P02=02-printf-etc
P03=03-loop
P04=04-argc-argv
P05=05-envp
P06=06-scan
P07=07-status
P08=08-pointer
P09=09-function
P10=10-uts171
P11=11-uts172
P12=12-uts181
P13=13-uts182
P14=14-uts191
P15=15-uts192
P16=16-uts201
P17=17-uts232


EXECS= \
   $(P00) \
   $(P01) \
   $(P02) \
   $(P03) \
   $(P04) \
   $(P05) \
   $(P06) \
   $(P07) \
   $(P08) \
   $(P09) \
   $(P10) \
   $(P11) \
   $(P12) \
   $(P13) \
   $(P14) \
   $(P15) \
   $(P16) \
   $(P17) \


DEMOFILES=\
	demo.txt \
        

MODE644=\
	demo.txt \


all:  $(EXECS) demo.txt

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.phony: clean demo

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo: demo.txt
demo.txt:
	@echo "Line 1: Blah Blah Blah 1" >  demo.txt
	@echo "Line 2: Blah Blah Blah 2" >> demo.txt
	@echo "Line 3: Blah Blah Blah 3" >> demo.txt
	@chmod 644 $(MODE644)


