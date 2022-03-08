main: main.o funcs.o
	g++ -o main main.o funcs.o 

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

funcs.o: funcs.cpp funcs.h 

main.o: main.cpp funcs.h 
	g++ -c main.cpp -std=c++11

tests.o: tests.cpp doctest.h funcs.h 
	g++ -c tests.cpp -std=c++11

clean:
	rm -f main.o funcs.o tests.o
