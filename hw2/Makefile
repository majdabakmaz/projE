SRC=$(wildcard src/*c)
EXESRC=$(wildcard exesrc/*o)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/

CFLAGS=-I $(INC)
EXE=exe/test_dft.elf exe/test_idft.elf

.SECONDARY:

all: $(EXE)

exe/%.elf: exesrc/%.o $(OBJ) 
	gcc $< $(OBJ) -lm -o $@

%.o: %.c
	gcc -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ) $(EXE) $(EXESRC) *.bin

run:
	./exe/test_dft.elf ./exe/test_idft.elf


