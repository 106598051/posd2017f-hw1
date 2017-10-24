all: hw4

hw4: mainList.o variable.o atom.o number.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw4 mainList.o variable.o atom.o number.o struct.o list.o -lgtest
else
	g++ -o hw4 mainList.o variable.o atom.o number.o struct.o list.o -lgtest -lpthread
endif

mainList.o: mainList.cpp utList.h utVariable.h utStruct.h
	g++ --std=gnu++11 -c mainList.cpp
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

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw4
endif
