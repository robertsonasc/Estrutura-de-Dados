####################### Makefile ##########################
all: Queue
Queue: Queue.o main.o 
	# O compilador faz a ligação entre os dois objetos
	g++ -o prog Queue.o main.o
Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp -W -Wall
main.o: main.cpp Queue.h
	g++ -c main.cpp -W -Wall
clean:
	rm -rf *.o
mrproper: clean
	rm -rf Queue
