; this file contains external references to functions implemented in c which 
; replace an original asm implementation. the contents in this file has to be
; kept in sync with the names of ported functions in PortFuncName in anders.idc

; forward for crt hack in seg010.asm

endseg segment byte private 'ENDSEG' use16
endseg ends

; externs for implementations in frame.c
extrn update_frame:proc

; externs for implementations in save_opt.c
extrn load_graphic_options:proc
extrn save_graphic_options:proc

extrn stuntsmain:proc
