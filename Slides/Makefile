# REV284 Fri 12 Mar 2021 07:29:51 WIB
# REV238 Sun Sep 13 11:18:18 WIB 2020
# REV151 Thu Aug 16 22:40:32 WIB 2018
# REV002 Mon May 22 09:37:31 WIB 2017
# START  Tue Sep 13 09:30:20 WIB 2016
# Adapted from Tobias Oetiker
###########################################################################

SHELL = /bin/bash
# Define some variables
# MAKEINDEX=makeindex
BRP00=src/os00-BRP.tex src/os00-TIPS.tex
BRP01=src/os01-BRP.tex
BRP02=src/os02-BRP.tex
BRP03=src/os03-BRP.tex
BRP04=src/os04-BRP.tex
BRP05=src/os05-BRP.tex
BRP06=src/os06-BRP.tex
BRP07=src/os07-BRP.tex
BRP08=src/os08-BRP.tex
BRP09=src/os09-BRP.tex
BRP10=src/os10-BRP.tex
BRP=${BRP00} ${BRP01} ${BRP02} ${BRP03} ${BRP04} ${BRP05} ${BRP06} ${BRP07} ${BRP08} ${BRP09} ${BRP10}
INCFILES=Makefile src/osII-jadwal.tex src/beamer.tex src/osHH.tex
PDFLATEX=pdflatex
PDFFILES= \
	os00.pdf \
	os01.pdf \
	os02.pdf \
	os03.pdf \
	os04.pdf \
	os05.pdf \
	os06.pdf \
	os07.pdf \
	os08.pdf \
	os09.pdf \
	os10.pdf \


# The default targets
all: $(PDFFILES)

# 12 ######################################################################
os00.pdf: src/os00.tex ${INCFILES} ${BRP}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os00 && \
	 $(PDFLATEX) os00 && \
	 $(PDFLATEX) os00 && \
	 mv os00.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os01.pdf: src/os01.tex ${INCFILES} ${BRP01}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os01 && \
	 $(PDFLATEX) os01 && \
	 $(PDFLATEX) os01 && \
	 mv os01.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os02.pdf: src/os02.tex ${INCFILES} ${BRP02}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os02 && \
	 $(PDFLATEX) os02 && \
	 $(PDFLATEX) os02 && \
	 mv os02.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os03.pdf: src/os03.tex ${INCFILES} ${BRP03}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os03 && \
	 $(PDFLATEX) os03 && \
	 $(PDFLATEX) os03 && \
	 mv os03.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os04.pdf: src/os04.tex ${INCFILES} ${BRP04}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os04 && \
	 $(PDFLATEX) os04 && \
	 $(PDFLATEX) os04 && \
	 mv os04.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os05.pdf: src/os05.tex ${INCFILES} ${BRP05}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os05 && \
	 $(PDFLATEX) os05 && \
	 $(PDFLATEX) os05 && \
	 mv os05.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os06.pdf: src/os06.tex ${INCFILES} ${BRP06}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os06 && \
	 $(PDFLATEX) os06 && \
	 $(PDFLATEX) os06 && \
	 mv os06.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os07.pdf: src/os07.tex ${INCFILES} ${BRP07}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os07 && \
	 $(PDFLATEX) os07 && \
	 $(PDFLATEX) os07 && \
	 mv os07.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os08.pdf: src/os08.tex ${INCFILES} ${BRP08}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os08 && \
	 $(PDFLATEX) os08 && \
	 $(PDFLATEX) os08 && \
	 mv os08.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os09.pdf: src/os09.tex ${INCFILES} ${BRP09}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os09 && \
	 $(PDFLATEX) os09 && \
	 $(PDFLATEX) os09 && \
	 mv os09.pdf .. )
	 rm pdfbuild/*

# 12 ######################################################################
os10.pdf: src/os10.tex ${INCFILES} ${BPR10}
	-mkdir pdfbuild
	(TEXINPUTS=.:`pwd`/src:${TEXINPUTS:-:} && \
	 export TEXINPUTS && \
         cd pdfbuild && \
	 $(PDFLATEX) os10 && \
	 $(PDFLATEX) os10 && \
	 $(PDFLATEX) os10 && \
	 mv os10.pdf .. )
	 rm pdfbuild/*

# ## ######################################################################
cleanpdf: clean
	rm -f $(PDFFILES)

clean:
	rm -rf pdfbuild
	rm -f src/*.tex.bak

xfer:
	chmod 644 *.pdf  src/*
	cp os??.pdf ~/tmp/
	cp check??.pdf ~/tmp/

