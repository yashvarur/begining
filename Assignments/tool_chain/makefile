.PHONY:clean
INCLUDE=header
VPATH=./source ./object
SRC= $(shell ls ./source)
OBJ=$(SRC:.c=.o)
EXE: $(OBJ)
	gcc -o $@ $^
	rm main.o
	mv *.o ./object
%.o:%.c
	gcc -Wall -c $^ -I $(INCLUDE)
clean:
	rm ./object/*.o
	rm EXE


