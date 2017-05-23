Simple Image Viewer
----------------------

Simple Image Viewer, what a cool name uhn? 

It was created for educational purpose and aims to challenge the students into completing the assembly code located on asm_fnc*.* files. This can be done by using *jwasm* (asm_fnc.masm asm_fncx86.masm), *nasm* (asm_fnc.asm, asm_fncx86.asm) or *gnuasm* (asm_fnc.s asm_fncx86.s)


Installing dependencies
--------------------------

In order to install all required dependencies to compile the whole project 
properly, run:

	$ ./dependencies.sh 	#At the root of the project file system.
 
It will detect whether you are running archlinux, debian or ubuntu, and automatically
choose by then, how to install all required dependencies.


Compiling the project
--------------------------

Since the project is developed to work with one of the compillers already 
informed above, to compile the project you have to choose what assembler you 
are willing to use, you can do so by doing:

	$ make <assembler>

Example, in case of compiling with nasm for x86 architecture you might do:

	$ make nasm86

similarly, if you want to use nasm x86_64 version you can do:

	$ make nasm

Keep in mind that the default assembler choosen is masm for x86 architecture, 
so if you type only:

	$ make 

It will compile using masm x86, as if you typed "make masm86". 


---

![alt text](http://i.imgur.com/ozz9QGq.png)
