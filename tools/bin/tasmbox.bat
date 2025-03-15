@echo off

set SRC_CFG=%~dp0dosbox.tmpl.conf
set DST_CFG=%~dp0tasm.dosbox.conf

del %DST_CFG% 2>nul
copy %SRC_CFG% %DST_CFG% >nul

(
  echo [autoexec]
  echo MOUNT S S:\
  echo S:
  echo SET PATH=s:\tools\bin;%%PATH%%
  echo cd %CD%
  echo del %5
  echo tasmx %* ^>tasmbox.out
  echo if ERRORLEVEL 0 goto noerror
  echo type tasmbox.out
  echo pause
  echo :noerror
  echo exit
) >> %DST_CFG%

set SDL_VIDEODRIVER=dummy
dosbox -conf %DST_CFG% -noconsole

del %DST_CFG% 2>nul
type tasmbox.out
del tasmbox.out 2>nul