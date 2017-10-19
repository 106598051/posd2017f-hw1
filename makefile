all: hw3

hw3: mainTerm.o variable.o atom.o number.o struct.o
ifeq (${OS}, Windows_NT)
	g++ -o hw3 mainTerm.o variable.o atom.o number.o struct.o -lgtest
else
	g++ -o hw3 mainTerm.o variable.o atom.o number.o struct.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utVariable.h utStruct.h
	g++ --std=gnu++11 -c mainTerm.cpp
variable.o: variable.cpp variable.h
	g++ --std=gnu++11 -c variable.cpp
atom.o: atom.cpp atom.h
	g++ --std=gnu++11 -c atom.cpp
number.o: number.cpp number.h
	g++ --std=gnu++11 -c number.cpp
struct.o: struct.cpp struct.h
	g++ --std=gnu++11 -c struct.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw3
endif
