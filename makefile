file = main
supporter = DT
complier = clang++

run:$(file).o $(supporter).o
	$(complier) -o run $(file).o $(supporter).o
$(file).o:$(file).cpp
	$(complier) -c -g $(file).cpp
$(supporter).o:$(supporter).cpp $(supporter).h
	$(complier) -c -g $(supporter).cpp
clean:
	rm *.o
	rm run
