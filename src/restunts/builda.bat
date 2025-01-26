tasmx /m2 /s /zi asmorig/dseg.asm     build/dseg.obj
tasmx /m2 /s /zi asmorig/seg000.asm   build/seg000.obj
tasmx /m2 /s /zi asmorig/seg001.asm   build/seg001.obj
tasmx /m2 /s /zi asmorig/seg002.asm   build/seg002.obj
tasmx /m2 /s /zi asmorig/seg003.asm   build/seg003.obj
tasmx /m2 /s /zi asmorig/seg004.asm   build/seg004.obj
tasmx /m2 /s /zi asmorig/seg005.asm   build/seg005.obj
tasmx /m2 /s /zi asmorig/seg006.asm   build/seg006.obj
tasmx /m2 /s /zi asmorig/seg007.asm   build/seg007.obj
tasmx /m2 /s /zi asmorig/seg008.asm   build/seg008.obj
tasmx /m2 /s /zi asmorig/seg009.asm   build/seg009.obj
tasmx /m2 /s /zi asmorig/seg010.asm   build/seg010.obj
tasmx /m2 /s /zi asmorig/seg011.asm   build/seg011.obj
tasmx /m2 /s /zi asmorig/seg012.asm   build/seg012.obj
tasmx /m2 /s /zi asmorig/seg013.asm   build/seg013.obj
tasmx /m2 /s /zi asmorig/seg014.asm   build/seg014.obj
tasmx /m2 /s /zi asmorig/seg015.asm   build/seg015.obj
tasmx /m2 /s /zi asmorig/seg016.asm   build/seg016.obj
tasmx /m2 /s /zi asmorig/seg017.asm   build/seg017.obj
tasmx /m2 /s /zi asmorig/seg018.asm   build/seg018.obj
tasmx /m2 /s /zi asmorig/seg019.asm   build/seg019.obj
tasmx /m2 /s /zi asmorig/seg020.asm   build/seg020.obj
tasmx /m2 /s /zi asmorig/seg021.asm   build/seg021.obj
tasmx /m2 /s /zi asmorig/seg022.asm   build/seg022.obj
tasmx /m2 /s /zi asmorig/seg023.asm   build/seg023.obj
tasmx /m2 /s /zi asmorig/seg024.asm   build/seg024.obj
tasmx /m2 /s /zi asmorig/seg025.asm   build/seg025.obj
tasmx /m2 /s /zi asmorig/seg026.asm   build/seg026.obj
tasmx /m2 /s /zi asmorig/seg027.asm   build/seg027.obj
tasmx /m2 /s /zi asmorig/seg028.asm   build/seg028.obj
tasmx /m2 /s /zi asmorig/seg029.asm   build/seg029.obj
tasmx /m2 /s /zi asmorig/seg030.asm   build/seg030.obj
tasmx /m2 /s /zi asmorig/seg031.asm   build/seg031.obj
tasmx /m2 /s /zi asmorig/seg032.asm   build/seg032.obj
tasmx /m2 /s /zi asmorig/seg033.asm   build/seg033.obj
tasmx /m2 /s /zi asmorig/seg034.asm   build/seg034.obj
tasmx /m2 /s /zi asmorig/seg035.asm   build/seg035.obj
tasmx /m2 /s /zi asmorig/seg036.asm   build/seg036.obj
tasmx /m2 /s /zi asmorig/seg037.asm   build/seg037.obj
tasmx /m2 /s /zi asmorig/seg038.asm   build/seg038.obj
tasmx /m2 /s /zi asmorig/seg039.asm   build/seg039.obj
tasmx /m2 /s /zi asmorig/seg041.asm   build/seg041.obj
tasmx /m2 /s /zi asmorig/segments.asm build/segments.obj

bcc -I../c dos/main.c build/main.obj

tlink /s /P- /v /js:\tools\lib\ build\*.obj stuntsa.exe


