all: clean hw6

hw6: mainParser.o variable.o atom.o number.o struct.o list.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o hw6 mainParser.o variable.o atom.o number.o struct.o list.o term.o -lgtest
else
	g++ -o hw6 mainParser.o variable.o atom.o number.o struct.o list.o term.o -lgtest -lpthread
endif

mainParser.o: mainParser.cpp utParser.h
	g++ --std=gnu++11 -c mainParser.cpp
variable.o: variable.cpp variable.h
	g++ --std=gnu++11 -c variable.cpp
atom.o: atom.cpp atom.h
	g++ --std=gnu++11 -c atom.cpp
number.o: number.cpp number.h
	g++ --std=gnu++11 -c number.cpp
struct.o: struct.cpp struct.h
	g++ --std=gnu++11 -c struct.cpp
list.o: list.cpp list.h
	g++ --std=gnu++11 -c list.cpp
term.o: term.cpp term.h
	g++ --std=gnu++11 -c term.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw6
endif
