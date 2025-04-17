# options
CONFIG ?= release
ASSEMBLER ?= tasm32
LINKER ?= tlinkbox

VALID_CONFIGS = debug release

VALID_ASSEMBLERS = tasmbox tasmx tasm32

BORLAND_LINKERS = tlinkbox tlink
VALID_LINKERS = $(BORLAND_LINKERS) wlink

# valid CONFIG
ifeq (,$(findstring $(CONFIG),$(VALID_CONFIGS)))
  $(error unknown CONFIG value: $(CONFIG))
endif

# valid ASSEMBLER
ifeq (,$(findstring $(ASSEMBLER),$(VALID_ASSEMBLERS)))
  $(error unknown ASSEMBLER value: $(ASSEMBLER))
endif

# valid LINKER
ifeq (,$(findstring $(LINKER),$(VALID_LINKERS)))
  $(error unknown LINKER value: $(LINKER))
endif

# valid option combination
ifeq ($(CONFIG),debug)
  ifeq ($(ASSEMBLER),tasm32)
    $(error ASSEMBLER $(ASSEMBLER) is not supported for CONFIG $(CONFIG))
  endif
  ifeq ($(LINKER),wlink)
    $(error LINKER $(LINKER) is not supported for CONFIG $(CONFIG))
  endif
endif

MAKE_PARAMS = CONFIG=$(CONFIG) ASSEMBLER=$(ASSEMBLER) LINKER=$(LINKER)

restunts: asm c
	make -C dos $(MAKE_PARAMS)

restunts-original: asmorig
	make -C dos TARGET=original $(MAKE_PARAMS)

asm: force_me
	make -C asm $(MAKE_PARAMS)

asmorig: force_me
	make -C asmorig $(MAKE_PARAMS)

c: force_me
	make -C c $(MAKE_PARAMS)

restunts-sdl:
	make -C sdl $(MAKE_PARAMS)

repldump: asm c
	make -C repldump $(MAKE_PARAMS)

repldump-original: asmorig
	make -C repldump TARGET=original $(MAKE_PARAMS)

clean:
	make -C dos $(MAKE_PARAMS) clean
	make -C asm $(MAKE_PARAMS) clean
	make -C asmorig $(MAKE_PARAMS) clean
	make -C c $(MAKE_PARAMS) clean
	make -C sdl $(MAKE_PARAMS) clean
	make -C repldump clean

# i have no idea why i need to force pre-targets with an empty target
force_me: ;
