CC = gcc
NASM = nasm
PROGRAM = ./parser
BUILDFOLDER = build/
# all: test # fibo  larra swap struct loop
test1: test/test.c
	$(PROGRAM) test/test.c
	$(NASM) -f elf test/test.asm -o test.o 
	$(CC) -o output test.o io/asm_io.o -m32

clean:
	rm -rf build/
