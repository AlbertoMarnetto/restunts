!if ($(CONFIG)!=debug)
CONFIG=release
!endif

!if ($(TASM)!=32)
TASM=
!endif

!ifndef LINKER
LINKER=tlink
!endif
!if ($(LINKER)!=wlink) & ($(LINKER)!=tlink)
!error unkown LINKER value: $(LINKER)
!endif

restunts: asm c
	cd dos
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

restunts-original: asmorig
	cd dos
	if exist makefile make /DTARGET=original /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

asm:
	cd asm
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

asmorig:
	cd asmorig
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

c:
	cd c
	if exist makefile make /DCONFIG=$(CONFIG) /DTEXE=$(TEXE) /DLINKER=$(LINKER)
	cd ..

restunts-sdl:
	cd sdl
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

repldump: asm c
	cd repldump
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

repldump-original: asmorig
	cd repldump
	if exist makefile make /DTARGET=original /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

clean:
	cd dos
	if exist makefile make clean
	cd ..
	cd c
	if exist makefile make clean
	cd ..
	cd asm
	if exist makefile make clean
	cd ..
	cd asmorig
	if exist makefile make clean
	cd ..
	cd sdl
	if exist makefile make clean
	cd ..
	cd repldump
	if exist makefile make clean
	cd ..
