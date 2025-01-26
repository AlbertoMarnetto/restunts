:: cd asmfar
:: 
:: tasmx /m2 /s /zi dseg.asm     ..\build\
:: tasmx /m2 /s /zi seg000.asm   ..\build\
:: tasmx /m2 /s /zi seg001.asm   ..\build\
:: tasmx /m2 /s /zi seg002.asm   ..\build\
:: tasmx /m2 /s /zi seg003.asm   ..\build\
:: tasmx /m2 /s /zi seg004.asm   ..\build\
:: tasmx /m2 /s /zi seg005.asm   ..\build\
:: tasmx /m2 /s /zi seg006.asm   ..\build\
:: tasmx /m2 /s /zi seg007.asm   ..\build\
:: tasmx /m2 /s /zi seg008.asm   ..\build\
:: tasmx /m2 /s /zi seg009.asm   ..\build\
:: tasmx /m2 /s /zi seg010.asm   ..\build\
:: tasmx /m2 /s /zi seg011.asm   ..\build\
:: tasmx /m2 /s /zi seg012.asm   ..\build\
:: tasmx /m2 /s /zi seg013.asm   ..\build\
:: tasmx /m2 /s /zi seg014.asm   ..\build\
:: tasmx /m2 /s /zi seg015.asm   ..\build\
:: tasmx /m2 /s /zi seg016.asm   ..\build\
:: tasmx /m2 /s /zi seg017.asm   ..\build\
:: tasmx /m2 /s /zi seg018.asm   ..\build\
:: tasmx /m2 /s /zi seg019.asm   ..\build\
:: tasmx /m2 /s /zi seg020.asm   ..\build\
:: tasmx /m2 /s /zi seg021.asm   ..\build\
:: tasmx /m2 /s /zi seg022.asm   ..\build\
:: tasmx /m2 /s /zi seg023.asm   ..\build\
:: tasmx /m2 /s /zi seg024.asm   ..\build\
:: tasmx /m2 /s /zi seg025.asm   ..\build\
:: tasmx /m2 /s /zi seg026.asm   ..\build\
:: tasmx /m2 /s /zi seg027.asm   ..\build\
:: tasmx /m2 /s /zi seg028.asm   ..\build\
:: tasmx /m2 /s /zi seg029.asm   ..\build\
:: tasmx /m2 /s /zi seg030.asm   ..\build\
:: tasmx /m2 /s /zi seg031.asm   ..\build\
:: tasmx /m2 /s /zi seg032.asm   ..\build\
:: tasmx /m2 /s /zi seg033.asm   ..\build\
:: tasmx /m2 /s /zi seg034.asm   ..\build\
:: tasmx /m2 /s /zi seg035.asm   ..\build\
:: tasmx /m2 /s /zi seg036.asm   ..\build\
:: tasmx /m2 /s /zi seg037.asm   ..\build\
:: tasmx /m2 /s /zi seg038.asm   ..\build\
:: tasmx /m2 /s /zi seg039.asm   ..\build\
:: tasmx /m2 /s /zi seg041.asm   ..\build\
:: tasmx /m2 /s /zi segments.asm ..\build\
:: 
:: cd ..
:: 
:: bcc -I..\c dos\main.c build\main.obj
:: 
cd build

tlink /s /P- /v /js:\tools\lib\ @restunts.lnk

