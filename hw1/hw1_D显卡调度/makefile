all : main
main: main.o Task.h  Server.h
	g++ main.o -o main
main.o: main.cpp Task.h Server.h 
	g++ -c main.cpp -o main.o
clean:
	rm *.o main