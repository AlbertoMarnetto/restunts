!ifndef TARGET
TARGET=ported
!endif

SRC=s:\src\restunts

# just one space or + for tlink
SEP=+
!if ($(LINKER)==wlink)
# and comma for wlink
SEP=,
!endif

RESTUNTS_OBJDIR = $(SRC)\c\build\dos
RESTUNTS_OBJFILES = $(RESTUNTS_OBJDIR)\fileio.obj$(SEP)$(RESTUNTS_OBJDIR)\math.obj$(SEP)$(RESTUNTS_OBJDIR)\memmgr.obj$(SEP)$(RESTUNTS_OBJDIR)\restunts.obj $(SEP)$(RESTUNTS_OBJDIR)\shape3d.obj$(SEP)$(RESTUNTS_OBJDIR)\shape2d.obj$(SEP)$(RESTUNTS_OBJDIR)\keyboard.obj$(SEP)$(RESTUNTS_OBJDIR)\heapsort.obj$(SEP)$(RESTUNTS_OBJDIR)\frame.obj$(SEP)$(RESTUNTS_OBJDIR)\state.obj$(SEP)$(RESTUNTS_OBJDIR)\stateply.obj$(SEP)$(RESTUNTS_OBJDIR)\statecrs.obj$(SEP)$(RESTUNTS_OBJDIR)\statecar.obj

ASM_DIR = $(SRC)\asm
ASM_OBJDIR = $(ASM_DIR)\build
ASM_OBJFILES = $(ASM_OBJDIR)\segments.obj$(SEP)$(ASM_OBJDIR)\seg000.obj$(SEP)$(ASM_OBJDIR)\seg001.obj$(SEP)$(ASM_OBJDIR)\seg002.obj$(SEP)$(ASM_OBJDIR)\seg003.obj$(SEP)$(ASM_OBJDIR)\seg004.obj$(SEP)$(ASM_OBJDIR)\seg005.obj$(SEP)$(ASM_OBJDIR)\seg006.obj$(SEP)$(ASM_OBJDIR)\seg007.obj$(SEP)$(ASM_OBJDIR)\seg008.obj$(SEP)$(ASM_OBJDIR)\seg009.obj$(SEP)$(ASM_OBJDIR)\seg010.obj$(SEP)$(ASM_OBJDIR)\seg011.obj$(SEP)$(ASM_OBJDIR)\seg012.obj$(SEP)$(ASM_OBJDIR)\seg013.obj$(SEP)$(ASM_OBJDIR)\seg014.obj$(SEP)$(ASM_OBJDIR)\seg015.obj$(SEP)$(ASM_OBJDIR)\seg016.obj$(SEP)$(ASM_OBJDIR)\seg017.obj$(SEP)$(ASM_OBJDIR)\seg018.obj$(SEP)$(ASM_OBJDIR)\seg019.obj$(SEP)$(ASM_OBJDIR)\seg020.obj$(SEP)$(ASM_OBJDIR)\seg021.obj$(SEP)$(ASM_OBJDIR)\seg022.obj$(SEP)$(ASM_OBJDIR)\seg023.obj$(SEP)$(ASM_OBJDIR)\seg024.obj$(SEP)$(ASM_OBJDIR)\seg025.obj$(SEP)$(ASM_OBJDIR)\seg026.obj$(SEP)$(ASM_OBJDIR)\seg027.obj$(SEP)$(ASM_OBJDIR)\seg028.obj$(SEP)$(ASM_OBJDIR)\seg029.obj$(SEP)$(ASM_OBJDIR)\seg030.obj$(SEP)$(ASM_OBJDIR)\seg031.obj$(SEP)$(ASM_OBJDIR)\seg032.obj$(SEP)$(ASM_OBJDIR)\seg033.obj$(SEP)$(ASM_OBJDIR)\seg034.obj$(SEP)$(ASM_OBJDIR)\seg035.obj$(SEP)$(ASM_OBJDIR)\seg036.obj$(SEP)$(ASM_OBJDIR)\seg037.obj$(SEP)$(ASM_OBJDIR)\seg038.obj$(SEP)$(ASM_OBJDIR)\seg039.obj$(SEP)$(ASM_OBJDIR)\dseg.obj$(SEP)$(ASM_OBJDIR)\seg041.obj

ASMORIG_DIR = $(SRC)\asmorig
ASMORIG_OBJDIR = $(ASMORIG_DIR)\build
ASMORIG_OBJFILES = $(ASMORIG_OBJDIR)\segments.obj$(SEP)$(ASMORIG_OBJDIR)\seg000.obj$(SEP)$(ASMORIG_OBJDIR)\seg001.obj$(SEP)$(ASMORIG_OBJDIR)\seg002.obj$(SEP)$(ASMORIG_OBJDIR)\seg003.obj$(SEP)$(ASMORIG_OBJDIR)\seg004.obj$(SEP)$(ASMORIG_OBJDIR)\seg005.obj$(SEP)$(ASMORIG_OBJDIR)\seg006.obj$(SEP)$(ASMORIG_OBJDIR)\seg007.obj$(SEP)$(ASMORIG_OBJDIR)\seg008.obj$(SEP)$(ASMORIG_OBJDIR)\seg009.obj$(SEP)$(ASMORIG_OBJDIR)\seg010.obj$(SEP)$(ASMORIG_OBJDIR)\seg011.obj$(SEP)$(ASMORIG_OBJDIR)\seg012.obj$(SEP)$(ASMORIG_OBJDIR)\seg013.obj$(SEP)$(ASMORIG_OBJDIR)\seg014.obj$(SEP)$(ASMORIG_OBJDIR)\seg015.obj$(SEP)$(ASMORIG_OBJDIR)\seg016.obj$(SEP)$(ASMORIG_OBJDIR)\seg017.obj$(SEP)$(ASMORIG_OBJDIR)\seg018.obj$(SEP)$(ASMORIG_OBJDIR)\seg019.obj$(SEP)$(ASMORIG_OBJDIR)\seg020.obj$(SEP)$(ASMORIG_OBJDIR)\seg021.obj$(SEP)$(ASMORIG_OBJDIR)\seg022.obj$(SEP)$(ASMORIG_OBJDIR)\seg023.obj$(SEP)$(ASMORIG_OBJDIR)\seg024.obj$(SEP)$(ASMORIG_OBJDIR)\seg025.obj$(SEP)$(ASMORIG_OBJDIR)\seg026.obj$(SEP)$(ASMORIG_OBJDIR)\seg027.obj$(SEP)$(ASMORIG_OBJDIR)\seg028.obj$(SEP)$(ASMORIG_OBJDIR)\seg029.obj$(SEP)$(ASMORIG_OBJDIR)\seg030.obj$(SEP)$(ASMORIG_OBJDIR)\seg031.obj$(SEP)$(ASMORIG_OBJDIR)\seg032.obj$(SEP)$(ASMORIG_OBJDIR)\seg033.obj$(SEP)$(ASMORIG_OBJDIR)\seg034.obj$(SEP)$(ASMORIG_OBJDIR)\seg035.obj$(SEP)$(ASMORIG_OBJDIR)\seg036.obj$(SEP)$(ASMORIG_OBJDIR)\seg037.obj$(SEP)$(ASMORIG_OBJDIR)\seg038.obj$(SEP)$(ASMORIG_OBJDIR)\seg039.obj$(SEP)$(ASMORIG_OBJDIR)\dseg.obj$(SEP)$(ASMORIG_OBJDIR)\seg041.obj

OBJDIR = $(SRC)\dos\build\$(TARGET)
RESTUNTS_CFLAGS = /c /u- /mm /n$(OBJDIR) /v /DRESTUNTS_DOS

!if ($(TARGET)==ported)

CTARGETS = $(ASM_OBJFILES)$(SEP)$(RESTUNTS_OBJFILES)$(SEP)$(OBJDIR)\main.obj$(SEP)getvect.obj$(SEP)labs.obj$(SEP)memcpy.obj$(SEP)fmemcpy.obj$(SEP)h_ldiv.obj$(SEP)f_lxmul.obj$(SEP)f_scopy.obj$(SEP)h_lrsh.obj$(SEP)h_padd.obj$(SEP)h_pina.obj$(SEP)h_pada.obj$(SEP)f_pcmp.obj$(SEP)h_lursh.obj$(SEP)h_psbp.obj$(SEP)h_llsh.obj
OUTFILE = restunts.exe
CFLAGS =

!elif ($(TARGET)==original)

CTARGETS = $(ASMORIG_OBJFILES)$(SEP)$(OBJDIR)\main.obj
CFLAGS = /DRESTUNTS_ORIGINAL
OUTFILE = restunto.exe

!else
!error Unsupported DOS target: $(TARGET)
!endif

CC = bcc  $(RESTUNTS_CFLAGS) $(CFLAGS)
LINK = call tlinkbox

LFLAGS=
!if ($(CONFIG)==debug)
LFLAGS=/v
!endif

TOOLS_LIB=s:\tools\lib

restunts: $(OBJDIR)\main.obj
!if ($(LINKER)==wlink)
	wlink name $(OUTFILE) format dos option NOCASEEXACT PATH $(TOOLS_LIB) file $(CTARGETS) 
!else
	echo $(CTARGETS) > restunts.lnk
	echo $(OUTFILE) >> restunts.lnk
	$(LINK) /s /P- $(LFLAGS) /j$(TOOLS_LIB) @restunts.lnk
	del restunts.lnk
!endif
	copy $(OUTFILE) s:\stunts

$(OBJDIR)\main.obj: main.c
	$(CC) -I../c $?

clean:
	del build\*.obj
	del build\ported\*.obj
	del build\original\*.obj
	del restunts.exe
	del restunts.map
	del restunto.exe
	del restunto.map
