CC=gcc
NASM=nasm
MASM=jwasm
GAS=$(CC)
MASMX86FLAG=-elf -zcw -Fo asm_fnc.o
MASMFLAG=-elf64 -10 -zcw
NASMX86FLAG=-felf -o
NASMFLAG=-felf64 -o
GASFLAG=-c
CFLAG=--std=c11 -o
OBJ_FLAG=--std=c11 -c
PKGCONFIG=`pkg-config --libs --cflags gtk+-3.0`
EXEC=../simple_imagem_viewer
MAIN=main.c
MASMX86_FILE=asm_fncx86.masm
MASM_FILE=asm_fnc.masm
NASMX86_FILE=asm_fncx86.asm
NASM_FILE=asm_fnc.asm
GASX86_FILE=asm_fncx86.s
GAS_FILE=asm_fnc.s
ASM_OBJ=asm_fnc.o
C_OBJ=c_fnc.o
OBJ_FILES=$(ASM_OBJ) $(C_OBJ) editor-menu-bar.o editor-window.o editor-controller.o

all: masm86

masm86:libs_masm86
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

masm:libs_masm
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

nasm86:libs_nasm86
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

nasm:libs_nasm
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

gnuasm86:libs_gnuasm86
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

gnuasm:libs_gnuasm
	$(CC) $(OBJ_FILES) $(MAIN) $(CFLAG) $(EXEC) $(PKGCONFIG)

libs_masm86:
	$(MASM) $(MASMX86FLAG) $(MASMX86_FILE)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

libs_masm:
	$(MASM) $(MASMFLAG) $(MASM_FILE)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

libs_nasm86:
	$(NASM) $(NASMX86_FILE) $(NASMX86FLAG) $(ASM_OBJ)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch


libs_nasm:
	$(NASM) $(NASM_FILE) -l asm_fnc.lst $(NASMFLAG) $(ASM_OBJ)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o  $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

libs_gnuasm86:
	$(GAS) $(GASFLAG) $(GASX86_FILE) $(CFLAG) $(ASM_OBJ)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch


libs_gnuasm:
	$(GAS) $(GASFLAG) $(GAS_FILE)
	$(CC) c_fnc.c $(OBJ_FLAG)
	$(CC) editor-menu-bar.c editor-menu-bar.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) editor-menu-bar.o editor-window.c editor-window.h $(OBJ_FLAG) $(PKGCONFIG)
	$(CC) $(ASM_OBJ) editor-window.o $(C_OBJ) editor-controller.c editor-controller.h $(OBJ_FLAG) $(PKGCONFIG)
	rm -rf *.*.gch

clean:
	rm -rf *.o *.*.gch $(EXEC)

