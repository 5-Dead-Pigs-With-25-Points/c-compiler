CC = gcc
NASM = nasm
PROGRAM = ./parser
BUILDFOLDER = build/
all: array1d base function_normal function_recursive pointer1d struct
	cp array1d /home/share/output/
	cp base /home/share/output/
	cp function_normal /home/share/output/
	cp function_recursive /home/share/output/
	cp pointer1d /home/share/output/
	cp struct /home/share/output/
	
array1d: test/array1d.c
	$(PROGRAM) test/array1d.c
	$(NASM) -f elf test/array1d.asm -o array1d.o 
	$(CC) -o array1d array1d.o io/asm_io.o -m32
	chmod 777 array1d
base: test/base.c
	$(PROGRAM) test/base.c
	$(NASM) -f elf test/base.asm -o base.o 
	$(CC) -o base base.o io/asm_io.o -m32
	chmod 777 base
function_normal: test/function_normal.c
	$(PROGRAM) test/function_normal.c
	$(NASM) -f elf test/function_normal.asm -o function_normal.o 
	$(CC) -o function_normal function_normal.o io/asm_io.o -m32
	chmod 777 function_normal
function_recursive: test/function_recursive.c
	$(PROGRAM) test/function_recursive.c
	$(NASM) -f elf test/function_recursive.asm -o function_recursive.o 
	$(CC) -o function_recursive function_recursive.o io/asm_io.o -m32
	chmod 777 function_recursive
pointer1d: test/pointer1d.c
	$(PROGRAM) test/pointer1d.c
	$(NASM) -f elf test/pointer1d.asm -o pointer1d.o 
	$(CC) -o pointer1d pointer1d.o io/asm_io.o -m32
	chmod 777 pointer1d
struct: test/struct.c
	$(PROGRAM) test/struct.c
	$(NASM) -f elf test/struct.asm -o struct.o 
	$(CC) -o struct struct.o io/asm_io.o -m32
	chmod 777 struct
clean:
	rm -rf build/
