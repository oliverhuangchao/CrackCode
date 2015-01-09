cc = clang++
cflag = -c -g
<<<<<<< HEAD
file = 6
=======
file = 5
>>>>>>> 9e53afa236d0f5ff97f9b202e9a0c9d5de504c2f

run:main.o ${file}.o
	${cc} -o run main.o ${file}.o
main.o:main.cpp ${file}.h $(file).cpp
	${cc} ${cflag} main.cpp
${file}.o:${file}.h ${file}.cpp
	${cc} ${cflag} ${file}.cpp

clean:
	rm *.o
	rm run
