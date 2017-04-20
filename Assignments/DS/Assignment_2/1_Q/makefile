.PHONY : clean
CC=gcc -Wall
INCLUDE = ./header
VPATH = ./source ./object
SRC = $(shell ls ./source)
OBJ = $(SRC:.c=.o)
EXE : $(OBJ)
	$(CC) -g -o $@ $^ 
	rm main.o
	mv *.o ./object

%.o :%.c 
	$(CC) -c $^ -I $(INCLUDE)

clean:
	-@rm ./object/*.o
	 rm EXE


