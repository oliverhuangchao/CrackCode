file:=main
object:=linklist.o node.o
support:=linklist.cpp node.cpp 
CFlag:=-c -g -std=c++0x

run:main.o linklist.o node.o test.o
	clang++ -o run main.o linklist.o node.o test.o

main.o:main.cpp linklist.h node.h
	clang++ $(CFlag) main.cpp

linklist.o:linklist.h linklist.cpp node.h
	clang++ $(CFlag) linklist.cpp

node.o:node.h node.cpp
	clang++ $(CFlag) node.cpp

test.o:test.h test.cpp
	clang++ $(CFlag) test.cpp

clean:
	rm -f *.o
	rm -f run
