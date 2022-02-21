OBJECTS = main.o List.o node.o 
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o 
	$(CXX) -o main $(OBJECTS)

main.o: main.cpp List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

Clean: 
	rm -f $(OBJECTS)