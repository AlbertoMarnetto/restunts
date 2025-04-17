# example:
# make -f makefile.gnu ASSEMBLER=tasm32

TARGET ?= dos

ifneq ($(TARGET),dos)
  $(error Unsupported TARGET: $(TARGET))
endif

ifeq ($(ASSEMBLER),)
  $(error ASSEMBLER is not defined)
endif
SUPPORTED_ASSEMBLERS = tasmbox tasmx tasm32
ifeq ($(filter $(ASSEMBLER), $(SUPPORTED_ASSEMBLERS)),)
  $(error Unsupported assembler: $(ASSEMBLER))
endif

OBJDIR = build

ASM_FILES = segments.asm seg000.asm seg001.asm seg002.asm seg003.asm seg004.asm seg005.asm \
            seg006.asm seg007.asm seg008.asm seg009.asm seg010.asm seg011.asm seg012.asm \
            seg013.asm seg014.asm seg015.asm seg016.asm seg017.asm seg018.asm seg019.asm \
            seg020.asm seg021.asm seg022.asm seg023.asm seg024.asm seg025.asm seg026.asm \
            seg027.asm seg028.asm seg029.asm seg030.asm seg031.asm seg032.asm seg033.asm \
            seg034.asm seg035.asm seg036.asm seg037.asm seg038.asm seg039.asm seg041.asm dseg.asm

OBJ_FILES = $(addprefix $(OBJDIR)/, $(ASM_FILES:.asm=.obj))

TFLAGS = /zn
ifeq ($(CONFIG),debug)
  TFLAGS = /zi
endif

ASM = $(ASSEMBLER) /m2 /s $(TFLAGS)

INCLUDES = structs.inc

all: $(OBJ_FILES)

$(OBJDIR)/%.obj: %.asm $(INCLUDES)
  # asm file name
	$(eval ASM_FILE = $<)
  # obj filepath (slash replaced with backslash for tasmx)
	$(eval OBJ_FILE = $(subst /,\,$@))
  # assembler run
	$(ASM) $(ASM_FILE), $(OBJ_FILE)

clean:
	del $(OBJDIR)\*.obj
