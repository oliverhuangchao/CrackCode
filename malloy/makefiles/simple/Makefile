CFLAGS  = -g -Wall -Weffc++ -Wextra -pedantic
LDFLAGS = `sdl-config --libs` -lm -lSDL_ttf -lSDL_image -lexpat

run:	main.o student.o
	g++ ${CFLAGS} -o run main.o student.o ${LDFLAGS}

main.o:	main.cpp student.h
	g++ ${CFLAGS} -c main.cpp

student.o:	student.cpp student.h
	g++ ${CFLAGS} -c student.cpp

clean:
	rm -rf *.o
	rm -rf *~
	rm -rf run a.out
