#!/bin/bash
# START: Mon 07 Nov 2022 19:00

RESULT="$HOME/RESULT/W07/"
REPORT="$RESULT/WEEK07-DEMO-CHECK.txt"
IAM="ZCZC DEMOCHECK $(echo $(whoami)$(hostname)|tr 'A-Za-z' 'N-ZA-Mn-za-m')"

[ -d $RESULT ] || mkdir -pv $RESULT
[ -f $REPORT ] || touch     $REPORT

echo "DEMOCHECK"
echo $IAM > $REPORT

