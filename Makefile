SRC=src/

all: 
	make -C $(SRC) all

masm: 
	make -C $(SRC) masm

nasm86:
	make -C $(SRC) nasm86

nasm: 
	make -C $(SRC) nasm

clean: 
	make -C $(SRC) clean
	
