all: hw2

hw2: mainTerm.o Variable.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o Variable.o -lgtest
else
	g++ -o hw2 mainTerm.o Variable.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp utTerm.h
	g++ -std=c++11 -c mainTerm.cpp

Variable.o: Variable.cpp Variable.h
	g++ -std=c++11 -c Variable.cpp

clean:
ifeq (${OS}, Windows_NT)
	del *.o *.exe
else
	rm -f *.o hw2
endif
stat:
	wc *.h *.cpp
