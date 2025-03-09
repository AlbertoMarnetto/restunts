!ifndef CONFIG
CONFIG=release
!endif
!if ($(CONFIG)!=release) & ($(CONFIG)!=debug)
!error unknown CONFIG value: $(CONFIG)
!endif

!ifndef ASSEMBLER
ASSEMBLER=tasm32
!endif
!if ($(ASSEMBLER)!=tasmbox) & ($(ASSEMBLER)!=tasmx) & ($(ASSEMBLER)!=tasm32)
!error unknown ASSEMBLER value: $(ASSEMBLER)
!endif

!ifndef LINKER
LINKER=tlink
!endif
!if ($(LINKER)!=tlink) & ($(LINKER)!=wlink)
!error unknown LINKER value: $(LINKER)
!endif

!if ($(CONFIG)==debug)

# currently only Turbo Debugger info is supported

!if ($(ASSEMBLER)==tasm32)
!error ASSEMBLER: $(ASSEMBLER) is not supported for config: $(CONFIG)
!endif

!if ($(LINKER)==wlink)
!error LINKER: $(LINKER) is not supported for config: $(CONFIG)
!endif

!endif

restunts: asm c
	cd dos
	if exist makefile make /DCONFIG=$(CONFIG) /DTASM=$(TASM) /DLINKER=$(LINKER)
	cd ..

restunts-original: asmorig
	cd dos
	if exist makefile make /DTARGET=original /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

asm:
	cd asm
	if exist makefile make /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

asmorig:
	cd asmorig
	if exist makefile make /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

c:
	cd c
	if exist makefile make /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

restunts-sdl:
	cd sdl
	if exist makefile make /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

repldump: asm c
	cd repldump
	if exist makefile make /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
	cd ..

repldump-original: asmorig
	cd repldump
	if exist makefile make /DTARGET=original /DCONFIG=$(CONFIG) /DASSEMBLER=$(ASSEMBLER) /DLINKER=$(LINKER)
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
