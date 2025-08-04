TARGET ?= dos

OBJDIR = build\$(TARGET)

# Set up tools for DOS
ifeq ($(TARGET),dos)
  CC = bcc /c /u- /mm /v /n$(OBJDIR) /DRESTUNTS_DOS

# Set up tools for SDL
else ifeq ($(TARGET),sdl)
  SDLPATH = s:/src/sdl
  CC = cl /Zi /MD /c /I$(SDLPATH)/include /DRESTUNTS_SDL /Fo$(OBJDIR)/$?

# Unsupported target
else
  $(error Unsupported C target: $(TARGET))
endif

C_FILES = fileio.c math.c memmgr.c restunts.c shape3d.c shape2d.c keyboard.c heapsort.c \
          frame.c state.c stateply.c statecrs.c statecar.c

OBJ_FILES = $(addprefix $(OBJDIR)/, $(C_FILES:.c=.obj))
OBJ_FILES_BACKSLASH = $(subst /,\,$(OBJ_FILES))

all: $(OBJ_FILES)

$(OBJDIR)/%.obj: %.c
  # c file name
	$(eval C_FILE = $<)
  # compiler run
	$(CC) $(C_FILE)

clean:
	del $(OBJ_FILES_BACKSLASH)
