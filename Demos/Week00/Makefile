# (c) 2016-2022 BinKadal, Sdn. Bhd.
# REV06: Tue 15 Nov 2022 07:00
# REV05: Thu 15 Sep 2022 07:00
# REV04: Fri  2 Apr 2021 07:00
# REV03: Fri  7 Feb 2020 00:00
# REV01: Tue 22 Aug 2017 14:00
# START: Fri 01 Jan 2016 00:00
# This is a free Makefile configuration.

# INFO: With this "Makefile", just run:
# INFO:                     make

PROGRAM=example

ALL:	$(PROGRAM)

$(PROGRAM): $(PROGRAM).c
	gcc -std=gnu18 -o $(PROGRAM) $(PROGRAM).c

clean:
	rm -f $(PROGRAM)

.phony: ALL clean

