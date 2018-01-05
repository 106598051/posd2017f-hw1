all: hw8 shell

hw8: mainShell.o variable.o atom.o number.o struct.o list.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o hw8 mainShell.o variable.o atom.o number.o struct.o list.o term.o -lgtest
else
	g++ -o hw8 mainShell.o variable.o atom.o number.o struct.o list.o term.o -lgtest -lpthread
endif

shell: shell.o variable.o atom.o number.o struct.o list.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o shell shell.o variable.o atom.o number.o struct.o list.o term.o -lgtest
else
	g++ -o shell shell.o variable.o atom.o number.o struct.o list.o term.o -lgtest -lpthread
endif

mainShell.o: mainShell.cpp exception.h expression.h
	g++ --std=gnu++0x -c mainShell.cpp
variable.o: variable.cpp variable.h
	g++ --std=gnu++0x -c variable.cpp
atom.o: atom.cpp atom.h
	g++ --std=gnu++0x -c atom.cpp
number.o: number.cpp number.h
	g++ --std=gnu++0x -c number.cpp
struct.o: struct.cpp struct.h
	g++ --std=gnu++0x -c struct.cpp
list.o: list.cpp list.h
	g++ --std=gnu++0x -c list.cpp
term.o: term.cpp term.h
	g++ --std=gnu++0x -c term.cpp

shell.o: shell.cpp
	g++ --std=gnu++0x -c shell.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw8
endif
