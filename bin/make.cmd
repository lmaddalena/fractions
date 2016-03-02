cl ../*.c /Fe:test.exe
lib.exe /out:fractions.lib fractions.obj
cl /LD ../fractions.c /Fe:fractions.dll
