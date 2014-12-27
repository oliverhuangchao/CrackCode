file:=main
CFlag:=-c -g -std=c++0x

run:main.o linklist.o node.o getData.o
	clang++ -o run main.o linklist.o node.o getData.o

main.o:main.cpp linklist.h node.h
	clang++ $(CFlag) main.cpp

linklist.o:linklist.h linklist.cpp node.h
	clang++ $(CFlag) linklist.cpp

node.o:node.h node.cpp
	clang++ $(CFlag) node.cpp

getData.o:getData.h getData.cpp
	clang++ $(CFlag) getData.cpp

clean:
	rm -f *.o
	rm -f run
