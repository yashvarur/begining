.PHONY:clean
CC=gcc -Wall
INCLUDE=header
VPATH=./source ./object 
OBJ=main.o function.o 
EXE:$(OBJ)
	$(CC) -o $@  $^
	rm main.o 
	mv *.o ./object
%.o:%.c
	$(CC) -c $^ -I $(INCLUDE)
clean:
	rm ./object/*.o
	rm EXE
