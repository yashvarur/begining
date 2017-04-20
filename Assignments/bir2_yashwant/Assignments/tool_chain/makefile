.PHONY:clean
CC=gcc -Wall
EXE:main.o fun.o
        gcc -o EXE $^
        rm main.o
%.o:%.c
        gcc -c $^
clean: 
        rm ./object/*.o
        rm EXE

