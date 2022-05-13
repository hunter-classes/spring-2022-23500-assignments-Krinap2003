main: main.o Dictionary.o OList.o Node.o Person.o 
	g++ -o main main.o Dictionary.o OList.o Node.o Person.o 

tests: tests.o Dictionary.o OList.o Node.o Person.o 
	g++ -o tests main.o Dictionary.o OList.o Node.o Person.o 

main.o: main.cpp Dictionary.h Person.h OList.h Node.h
	g++ -c main.cpp -std=c++11

tests.o: tests.cpp Dictionary.h Person.h OList.h Node.h
	g++ -c tests.cpp -std=c++11

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

List.o: OList.cpp OList.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm -f main.o tests.o Dictionary.o Person.o OList.o Node.o main tests