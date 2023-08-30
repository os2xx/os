#!/bin/bash
# REV08: Sun 06 Aug 2023 12:00
# REV07: Tue 15 Nov 2022 07:00
# REV05: Tue 24 Mar 2020 11:00
# REV03: Wed 19 Feb 2020 15:00
# REV02: Wed 19 Feb 2020 07:00
# START: Fri 07 Feb 2020 00:00
# 
# Copyright (C) 2020-2023 BinKadal, Sdn. Bhd.
# This is a free script/software.

# INFO: This will generate file 000-READ-THIS-FIRST.txt

FILE="000-READ-THIS-FIRST.txt"
MEMOFILE=".zzz-doREADTHISFIRST"
FALLOC=15
PREFIX="^# INFO: "
ORIG="$(pwd)"

function INFO() {
   [ -e $1 ] && {
      RESULT=$(grep -E "$PREFIX" "$1" | cut -c9-)
      [ -z "$RESULT" ] || printf "[%${FALLOC}s] %s\n" "$1" "$RESULT"
   }
}

[ -z "$1" ]               || { INFO $1 ; exit 0; }
DATE=$(date "+%a %d %b %Y %H:00")
for II in \
.  \
.. \
../Week00/ \
../Week01/ \
../Week02/ \
../Week02/c-language/  \
../Week02/permissions/ \
../Week03/ \
../Week03/FUSE/  \
../Week03/Files/ \
../Week04/ \
../Week05/ \
../Week06/ \
../Week07/ \
../Week08/ \
../Week09/ \
../Week09/disk-images/ \
../Week09/systemd/ \
../Week10/ \
; do
   [ -f $II/$MEMOFILE ] && {
      pushd $II
      echo "# INFO: Read This First! ==== ========= ========="       >  $FILE
      echo "# Version: $DATE"                                       >> $FILE
      echo "cat \$0; exit 0;"                                       >> $FILE
      [ -f $ORIG/zzv-download.txt ]  && cat $ORIG/zzv-download.txt  >>  $FILE
      cat $MEMOFILE                                     >> $FILE
      for JJ in $(ls) ; do [ -f $JJ ] && INFO $JJ        >> $FILE ; done
      [ -f $ORIG/zzy-copyright.txt ] && cat $ORIG/zzy-copyright.txt >> $FILE
      popd
   }
done

exit 0

