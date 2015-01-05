file=sort
run:${file}.o
	clang++ -o run ${file}.o
${file}.o:${file}.cpp
	clang++ -c -g ${file}.cpp
clean:
	rm *.o
	rm run
