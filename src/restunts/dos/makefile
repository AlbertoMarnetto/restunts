# default target
TARGET ?= ported

SRC = s:\src\restunts

RESTUNTS_OBJ_FILES = frame.obj save_opt.obj stdio.obj

ASM_OBJ_FILES = segments.obj seg000.obj seg001.obj seg002.obj seg003.obj seg004.obj seg005.obj \
                seg006.obj seg007.obj seg008.obj seg009.obj seg010.obj seg011.obj seg012.obj \
                seg013.obj seg014.obj seg015.obj seg016.obj seg017.obj seg018.obj seg019.obj \
                seg020.obj seg021.obj seg022.obj seg023.obj seg024.obj seg025.obj seg026.obj \
                seg027.obj seg028.obj seg029.obj seg030.obj seg031.obj seg032.obj seg033.obj \
                seg034.obj seg035.obj seg036.obj seg037.obj seg038.obj seg039.obj seg041.obj dseg.obj

CM_LIB_FILES = getvect.obj labs.obj memcpy.obj \
               fmemcpy.obj h_ldiv.obj f_lxmul.obj f_scopy.obj \
               h_lrsh.obj h_padd.obj h_pina.obj h_pada.obj \
               f_pcmp.obj h_lursh.obj h_psbp.obj h_llsh.obj

# prefix with path
RESTUNTS_OBJDIR = $(SRC)\c\build\dos
ASM_OBJDIR = $(SRC)\asm\build
ASMORIG_OBJDIR = $(SRC)\asmorig\build
OBJDIR = $(SRC)\dos\build\$(TARGET)

RESTUNTS_OBJFILES = $(addprefix $(RESTUNTS_OBJDIR)\, $(RESTUNTS_OBJ_FILES))
ASM_OBJFILES = $(addprefix $(ASM_OBJDIR)\, $(ASM_OBJ_FILES))
ASMORIG_OBJFILES = $(addprefix $(ASMORIG_OBJDIR)\, $(ASM_OBJ_FILES))

# C Compiler Flags und Linker
RESTUNTS_CFLAGS = -c -u- -mm -n$(OBJDIR) -v -DRESTUNTS_DOS

ifeq ($(TARGET), ported)
  ALL_OBJ_FILES = $(ASM_OBJFILES) $(RESTUNTS_OBJFILES) $(OBJDIR)\main.obj $(CM_LIB_FILES)
  CFLAGS = 
  OUTFILE = restunts.exe
endif

ifeq ($(TARGET), original)
  ALL_OBJ_FILES = $(ASMORIG_OBJFILES) $(OBJDIR)\main.obj
  CFLAGS = -DRESTUNTS_ORIGINAL
  OUTFILE = restunto.exe
endif

# set linker separator
SEP := +
ifeq ($(LINKER),wlink)
  SEP := ,
endif
SPACE=$() $()
CTARGETS = $(subst $(SPACE),$(SEP),$(ALL_OBJ_FILES))

CC = bcc $(RESTUNTS_CFLAGS) $(CFLAGS)

LFLAGS = 
ifeq ($(CONFIG), debug)
  LFLAGS = /v
endif

TOOLS_LIB = s:\tools\lib

restunts: $(OBJDIR)/main.obj
  ifeq ($(LINKER), wlink)
		$(LINKER) name $(OUTFILE) format dos option NOCASEEXACT PATH $(TOOLS_LIB) file $(CTARGETS)
  else
    # create linker script for tlink
		echo $(CTARGETS) > lscript.txt
		echo $(OUTFILE) >> lscript.txt
		$(LINKER) /s /P- $(LFLAGS) /j$(TOOLS_LIB) @lscript.txt
		del lscript.txt
  endif
	copy $(OUTFILE) s:\stunts

$(OBJDIR)/main.obj: main.c
	$(CC) -I../c $?

clean:
	del build\*.obj
	del build\ported\*.obj
	del build\original\*.obj
	del restunts.exe
	del restunts.map
	del restunto.exe
	del restunto.map
