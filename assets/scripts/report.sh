#!/bin/bash
# Sun 26 Sep 2021 11:27:55 WIB

REPORT="usageW03.txt"
EXTRAS=60
MaxROOT=0
MaxMemory=0
MaxSwap="-1"

fecho(){
    echo "ZCZC $1" | tee -a $REPORT
}
expt() {
   local EXSTAMP=$(printf "%8.8X" $(( $(date +%s) & 16#FFFFFFFF )) )
   local EXCHSUM="XXXXXXXX"
   [ "$(hostname)" = "$USER" ] && {
       EXCHSUM=$(echo "$USER$EXSTAMP"|sha1sum|tr '[a-z]' '[A-Z]'| cut -c1-8)
   }
   fecho "expt $EXSTAMP $EXCHSUM"
   fecho "date $(date '+%y%m%d %H%M')"
   fecho "user $USER hostname $(hostname)"
}
echo "===== To EXIT,     press CONTROL-C ===== ====="
echo "===== Report File: $REPORT    ===== ====="
rm -f $REPORT
while true ; do
    expt
    LOOP=10
    while (( LOOP-- )) ; do
        TMP1=$(($(df|awk '/ \/$/ {print $3}')/1024))
        (( "$MaxROOT" < "$TMP1" )) && { MaxROOT=$TMP1; fecho "MaxRootFS ${MaxROOT}M" ; }
        TMP1=$(($(free|awk '/Mem:/ {print $3}')/1024))
        (( "$MaxMemory" < "$TMP1" )) && { MaxMemory=$TMP1; fecho "MaxMemory ${MaxMemory}M" ; }
        TMP1=$(($(free|awk '/Swap:/ {print $3}')/1024))
        (( "$MaxSwap" < "$TMP1" )) && { MaxSwap=$TMP1; fecho "MaxSwap ${MaxSwap}M" ; }
        sleep 6
    done
    sleep $((1+(++EXTRAS/60)))
    (( "$EXTRAS" > "60" )) && EXTRAS=0
done
exit

