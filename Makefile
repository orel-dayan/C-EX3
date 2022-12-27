CC= gcc
FLAGS= -Wall -g

all : txtfind isort

isort:
	$(CC) $(FLAGS) -o isort isort.c

txtfind: 
	$(CC) $(FLAGS) -o txtfind txtfind.c	

clean:
	rm  txtfind isort