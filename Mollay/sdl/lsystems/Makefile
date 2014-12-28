
ifeq ("$(shell whoami)", "malloy")
  CXX = g++
else
  CXX = g++
endif

# Warnings frequently signal eventual errors:
CXXFLAGS=`sdl-config --cflags` -g -W -Wall -Weffc++ -Wextra -pedantic -O0

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS =
else
  ifeq ("$(shell uname)", "Linux")
  LDFLAGS = `sdl-config --libs` -lSDL_ttf -lSDL_image -lexpat
  endif
endif

OBJS = \
	main.o \
	lsystem.o \
	parseXML.o \
	ioManager.o \
	aaline.o

EXEC = run

# $< refers to the first dependency
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# $@ refers to the target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

main.o: main.cpp lsystem.h
parseXML.o: parseXML.cpp parseXML.h
ioManager.o: ioManager.cpp ioManager.h
lsystem.o: lsystem.cpp lsystem.h ioManager.h parseXML.h aaline.cpp

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
