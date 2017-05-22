SRC=src/

all: 
	make -C $(SRC) all

masm: 
	make -C $(SRC) masm

nasm86:
	make -C $(SRC) nasm86

nasm: 
	make -C $(SRC) nasm

gnuasm86:
	make -C $(SRC) gnuasm86

gnuasm:
	make -C $(SRC) gnuasm

clean: 
	make -C $(SRC) clean
	
