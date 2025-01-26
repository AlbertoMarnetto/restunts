#! /bin/bash

@echo off
cp %./tools/bin/dosbox.tmpl.conf /tmp/tasm.dosbox.conf
cat << EOF >>  /tmp/tasm.dosbox.conf
[autoexec]
MOUNT S S:\
S:
SET PATH=%%PATH%%;s:\tools\bin
cd %CD%
tasmx %* ^>tasmbox.out
if ERRORLEVEL 0 goto noerror
type tasmbox.out
pause
:noerror
exit

EOF

dosbox -conf /tmp/tasm.dosbox.conf
cat tasmbox.out
