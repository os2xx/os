# REV08: Sat 28 Oct 2023 12:00
# REV07: Wed 25 Mar 2020 10:00
# REV05: Wed 24 Apr 2019 21:00
# REV04: Wed 14 Nov 2018 20:00
# REV03: Tue 01 May 2018 20:00
# START: Wed 18 Apr 2018 20:00

CC=gcc
CFLAGS=-std=gnu18 -pthread

P10=10-create-file
P11=11-create-mmap
P20=20-parent
P21=21-child
P22=22-hello-goodbye
P23=23-kirim-ambil
P50=50-181
P51=51-182
P52=52-182a
P53=53-182b
P54=54-191
P55=55-192a
P56=56-192b


EXECS= \
        $(P10) \
        $(P11) \
        $(P20) \
        $(P21) \
        $(P22) \
        $(P23) \
        $(P50) \
        $(P51) \
        $(P52) \
        $(P53) \
        $(P54) \
        $(P55) \
        $(P56) \


DEMOFILES=\
	demo-file.txt \
	demo-file.bin \
        

all:  $(EXECS)

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo:
	bash .shsh

