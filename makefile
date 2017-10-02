all: hw2

hw2: mainVariable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainVariable.o -lgtest
else
	g++ -o hw2 mainVariable.o -lgtest -lpthread
endif

mainVariable.o: mainVariable.cpp utVariable.h Variable.h
	g++ -std=c++11 -c mainVariable.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
stat:
	wc *.h *.cpp
