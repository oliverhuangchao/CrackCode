
ifeq ("$(shell whoami)", "malloy")
  CXX = g++
else
  CXX = g++
endif
CXX_LDFLAG = g++

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
	manager.o \
	gamedata.o \
	parseXML.o \
	clock.o \
	vector2f.o \
	sprite.o \
	frame.o \
	orbs.o \
	viewport.o \
	world.o \
	ioManager.o

EXEC = run

# $< refers to the first dependency
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# $@ refers to the target
$(EXEC): $(OBJS)
	$(CXX_LDFLAG) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

main.o: main.cpp
manager.o: manager.cpp manager.h gamedata.h ioManager.h sprite.h clock.h
ioManager.o: ioManager.cpp ioManager.h
parseXML.o: parseXML.cpp parseXML.h
gamedata.o: gamedata.cpp gamedata.h parseXML.h
spriteFactory.o: spriteFactory.cpp spriteFactory.h factory.h frame.h
clock.o: clock.cpp clock.h
vector2f.o: vector2f.cpp vector2f.h
frame.o: frame.cpp frame.h
sprite.o: sprite.cpp sprite.h drawable.h frame.h
frame.o: frame.cpp frame.h ioManager.h
orbs.o: orbs.cpp orbs.h sprite.h
viewport.o: viewport.cpp viewport.h sprite.h gamedata.h ioManager.h
world.o: world.cpp world.h frame.h gamedata.h viewport.h

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
