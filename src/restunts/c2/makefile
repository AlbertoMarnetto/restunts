!ifndef TARGET
TARGET=dos
!endif

OBJDIR = build\$(TARGET)

# Set up tools for DOS
!if ($(TARGET)==dos)
CC = bcc /c /u- /mm /v /n$(OBJDIR) /DRESTUNTS_DOS

# Set up tools for SDL
!elif ($(TARGET)==sdl)
SDLPATH = s:\src\sdl
CC = cl  /Zi /MD /c /I$(SDLPATH)\include /DRESTUNTS_SDL /Fo$(OBJDIR)\$?

!else
!error Unsupported C target: $(TARGET)
!endif


all: $(OBJDIR)\frame.obj

$(OBJDIR)\frame.obj: frame.c
	$(CC) $?

clean:
	del $(OBJDIR)\frame.obj
