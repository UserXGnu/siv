SRC=src/

all: 
	make -C $(SRC) all

nasm: 
	make -C $(SRC) nasm

masm: 
	make -C $(SRC) masm

clean: 
	make -C $(SRC) clean
	
