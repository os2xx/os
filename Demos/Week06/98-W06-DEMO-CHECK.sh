#!/bin/bash
# REV03: Tue 17 Oct 2023 09:00
# REV02: Sun 16 Apr 2023 02:00
# REV01: Mon 14 Nov 2022 03:00
# START: Mon 07 Nov 2022 19:00

WEEK="06"
DATE0="30-OCT-2023"
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

