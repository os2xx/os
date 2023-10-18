#!/bin/bash
# REV06: Wed 18 Oct 2023 11:00
# REV05: Sun 17 Sep 2023 08:00
# START: Mon 07 Nov 2022 19:00

# Copyright (C) 2018-2023 BinKadal, Sdn. Bhd.
# This program is free script/software. This program is distributed in the hope 
# that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# INFO: DEMO

WEEK="02"
DATE0="10-Sep-2023"
RESULT="$HOME/RESULT/W$WEEK/"
REPORT="$RESULT/WEEK$WEEK-DEMO-CHECK.txt"
IAM="DEMOCHECK $(echo $(whoami)W$WEEK$(hostname)|tr 'A-Za-z' 'N-ZA-Mn-za-m')"

hash4() {
  local tmpVAR=$(md5sum <<< "$@"|tr [a-f] [A-F])
  echo ${tmpVAR:0:4}
}
stamp() {
  local tmpVAR1=$(printf "%X" $((($(date +%s)-$(date --date="$DATE0" +%s))/86400%16)))
  local tmpVAR2=$(printf "%X" $((10#$(date +%H)*16/24)))
  local tmpVAR3=$(hash4 $RANDOM$RANDOM$RANDOM)
  local STAMP="${tmpVAR1: -1}$tmpVAR2${tmpVAR3:0:1}"
  echo $STAMP
}
fecho1() {
  echo ZCZC ${STAMP}$(hash4 "$STAMP$WHOAMI$@") $@
}
fecho() {
  fecho1 $@ | tee -a $REPORT
}

[ -d  $RESULT ] || mkdir -pv $RESULT
rm -f $REPORT
touch $REPORT
STAMP=$(stamp)

fecho $IAM





