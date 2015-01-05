file:=main
CFlag:=-c -g -std=c++0x

run:main.o linklist.o node.o getData.o bst.o Sort.o
	clang++ -o run main.o linklist.o node.o getData.o bst.o Sort.o

main.o:main.cpp node.h heap.h bst.h linklist.h Sort.h
	clang++ $(CFlag) main.cpp

linklist.o:linklist.h linklist.cpp node.h
	clang++ $(CFlag) linklist.cpp

#heap.o:heap.h heap.cpp node.h
#	clang++ $(CFlag) heap.cpp

bst.o:bst.h bst.cpp node.h
	clang++ $(CFlag) bst.cpp

node.o:node.h node.cpp
	clang++ $(CFlag) node.cpp

getData.o:getData.h getData.cpp
	clang++ $(CFlag) getData.cpp

Sort.o:Sort.h Sort.cpp
	clang++ $(CFlag) Sort.cpp

clean:
	rm -f *.o
	rm -f run
