SRC=src/

all: 
	make -C $(SRC) all 

masm86: 
	make -C $(SRC) masm86

masm: 
	make -C $(SRC) masm

clean: 
	make -C $(SRC) clean
	
