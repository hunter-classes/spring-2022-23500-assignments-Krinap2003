main: main.o stack.o queue.o Node.o List.o
	g++ -o main main.o stack.o queue.o Node.o List.o

tests: tests.o stack.o queue.o Node.o List.o
	g++ -o tests tests.o stack.o queue.o Node.o List.o

main.o: main.cpp stack.h queue.h
	g++ -c -g main.cpp -std=c++11

stack.o: stack.cpp stack.h

queue.o: queue.cpp queue.h

Node.o: Node.cpp Node.h

List.o: List.cpp List.h

tests.o: tests.cpp doctest.h stack.h queue.h
	g++ -c -g tests.cpp -std=c++11

clean:
	rm -f main.o tests.o stack.o queue.o Node.o List.o 
