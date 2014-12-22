file:=main
object:=linklist.o node.o
support:=linklist.cpp node.cpp 
CFlag:=-c -g -std=c++0x
run:$(file).o $(object)
	clang++ -o run $(file).o $(object)

$(file).o:$(file).cpp
	clang++ $(CFlag) $(file).cpp


$(object):$(support)
	clang++ $(CFlag) $(support)

clean:
	rm -f *.o
	rm -f run
