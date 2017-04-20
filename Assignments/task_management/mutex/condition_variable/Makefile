.PHONY:clean
CC=gcc -Wall
INCLUDE=header
VPATH=./source ./object 
OBJ=lock_algorithm.o 
EXE:$(OBJ)
	$(CC) -Wall  -o  $@  $^ -lpthread	
	mv *.o ./object
%.o:%.c
	$(CC) -c -g $^ -I $(INCLUDE) -lpthread 
clean:
	rm ./object/*.o
	
