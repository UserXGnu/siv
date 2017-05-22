CC=gcc
NASM=nasm
MASM=jwasm
MASMX86FLAG=-elf -zcw -Fo asm_fnc.o
NASMFLAG=-felf64 -o 
MASMFLAG=-elf64 -10 -zcw 
CFLAG=-o
OBJ_FLAG=-c
PKGCONFIG=`pkg-config --libs --cflags gtk+-3.0`
EXEC=../main
MAIN=main.c
NASM_FILE=asm_fnc.asm 
MASM_FILE=asm_fnc.masm
MASMX86_FILE=asm_fncx86.masm
ASM_OBJ=asm_fnc.o
OBJ_FILES=$(ASM_OBJ) editor-menu-bar.o editor-window.o editor-controller.o

all:libs_masm86
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG) 

nasm:libs_nasm
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG) 

masm:libs_masm
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG) 

libs_masm86:
	$(MASM) $(MASMX86FLAG) $(MASMX86_FILE)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o  editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

libs_nasm:
	$(NASM) $(NASM_FILE) $(NASMFLAG) $(ASM_OBJ)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o  editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

libs_masm:
	$(MASM) $(MASMFLAG) $(MASM_FILE)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o  editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

clean:
	rm -rf *.o *.*.gch $(EXEC)
