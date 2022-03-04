OBJECTS = main.o List.o Node.o OList.o ONode.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o List.o Node.o OList.o ONode.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o OList.o ONode.o
	$(CXX) -o tests tests.o List.o Node.o OList.o ONode.o

main.o: main.cpp List.h OList.h

tests.o: tests.cpp doctest.h List.h OList.h
	g++ -c tests.cpp -std=c++11

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h ONode.h

ONode.o: ONode.cpp ONode.h

clean: 
	rm -f $(OBJECTS) tests.o