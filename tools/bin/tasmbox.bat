@echo off

set SRC_CFG=%~dp0dosbox.tmpl.conf
set DST_CFG=%~dp0tasm.dosbox.conf

del %DST_CFG% 2>nul
copy %SRC_CFG% %DST_CFG% >nul

echo [autoexec] >> %DST_CFG%
echo MOUNT S S:\ >> %DST_CFG%
echo S: >> %DST_CFG%
echo SET PATH=s:\tools\bin;%%PATH%% >> %DST_CFG%
echo cd %CD% >> %DST_CFG%
echo del %5 >> %DST_CFG%
echo tasmx %* ^>tasmbox.out >> %DST_CFG%
echo if ERRORLEVEL 0 goto noerror >> %DST_CFG%
echo type tasmbox.out >> %DST_CFG%
echo pause >> %DST_CFG%
echo :noerror >> %DST_CFG%
echo exit >> %DST_CFG%

set SDL_VIDEODRIVER=dummy
dosbox -conf %DST_CFG% -noconsole

del %DST_CFG% 2>nul
type tasmbox.out
del tasmbox.out 2>nul