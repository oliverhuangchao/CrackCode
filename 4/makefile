cc = clang++
cflag = -c -g -std=c++0x
file = code

run:main.o ${file}.o
	${cc} -o run main.o ${file}.o
main.o:main.cpp ${file}.h $(file).cpp
	${cc} ${cflag} main.cpp
${file}.o:${file}.h ${file}.cpp
	${cc} ${cflag} ${file}.cpp

clean:
	rm *.o
	rm run
