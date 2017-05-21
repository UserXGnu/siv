SRC=src/

all: 
	make -C $(SRC) all 

masm: 
	make -C $(SRC) masm

clean: 
	make -C $(SRC) clean
	
