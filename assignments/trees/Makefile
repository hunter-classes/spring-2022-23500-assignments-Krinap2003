OBJECTS=main.o BSTree.o Node.o 
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

tests: tests.o BSTree.o Node.o
	g++ -o tests tests.o BSTree.o Node.o

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

tests.o: tests.cpp Node.h BSTree.h
	g++ -c -g tests.cpp  -std=c++11

Node.o: Node.cpp Node.h
 
clean:
	rm -f $(OBJECTS) main tests.o tests