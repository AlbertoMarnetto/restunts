@echo off

set SRC_CFG=%~dp0dosbox.tmpl.conf
set DST_CFG=%~dp0tlink.dosbox.conf

del %DST_CFG% 2>nul
copy %SRC_CFG% %DST_CFG% >nul

echo [autoexec] >> %DST_CFG%
echo MOUNT S S:\ >> %DST_CFG%
echo S: >> %DST_CFG%
echo SET PATH=%%PATH%%;s:\tools\bin >> %DST_CFG%
echo cd %CD% >> %DST_CFG%
echo tlink %* ^>tlinkbox.out >> %DST_CFG%
echo if ERRORLEVEL 0 goto noerror >> %DST_CFG%
echo type tlinkbox.out >> %DST_CFG%
echo pause >> %DST_CFG%
echo :noerror >> %DST_CFG%
echo exit >> %DST_CFG%


set SDL_VIDEODRIVER=dummy
dosbox -conf %DST_CFG% -noconsole

del %DST_CFG% 2>nul
type tlinkbox.out
del tlinkbox.out 2>nul
