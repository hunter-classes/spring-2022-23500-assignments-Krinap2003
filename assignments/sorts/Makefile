main: main.o sorts.o mode.o
	g++ -o main main.o sorts.o mode.o

tests: tests.o sorts.o mode.o
	g++ -o tests tests.o sorts.o mode.o

sorts.o: sorts.cpp sorts.h 
	g++ -c sorts.cpp -std=c++11

mode.o: mode.cpp sorts.h
	g++ -c mode.cpp -std=c++11

main.o: main.cpp sorts.h 
	g++ -c main.cpp -std=c++11

tests.o: tests.cpp doctest.h sorts.h 
	g++ -c tests.cpp -std=c++11

clean:
	rm -f main.o sorts.o tests.o mode.o
