#include <iostream>
#include <string>

#include "clock.h"

Clock& Clock::getInstance() {
  if ( SDL_WasInit(SDL_INIT_VIDEO) == 0) {
    throw std::string("Must init SDL before Clock");
  }
  static Clock clock; 
  return clock;
}

Clock::Clock() :
  started(false), 
  paused(false), 
  frames(0), 
  timeAtStart(0), timeAtPause(0),
  currTicks(0), prevTicks(0), ticks(0) 
  {
  start();
}

Clock::Clock(const Clock& c) :
  started(c.started), 
  paused(c.paused), frames(c.frames), 
  timeAtStart(c.timeAtStart), timeAtPause(c.timeAtPause),
  currTicks(c.currTicks), prevTicks(c.prevTicks), ticks(c.ticks) 
{
  start();
}

void Clock::debug( ) { 
  std::cout << "The clock is:" << std::endl;
  std::cout << "\tstarted:" << started << std::endl;
  std::cout << "\tpaused:" << paused << std::endl;
  std::cout << "\tframes:" << frames << std::endl;
  std::cout << "\ttimeAtStart:" << timeAtStart << std::endl;
  std::cout << "\ttimeAtPause:" << timeAtPause << std::endl;
  std::cout << "\tcurrTicks:" << currTicks << std::endl;
  std::cout << "\tprevTicks:" << prevTicks << std::endl;
  std::cout << "\tticks:" << ticks << std::endl;
  std::cout << std::endl;
}

unsigned Clock::getTicks() const { 
  if (paused) return timeAtPause;
  else return SDL_GetTicks() - timeAtStart; 
}

unsigned Clock::getElapsedTicks() { 
  if (paused) return 0;
  currTicks = getTicks();
  ticks = currTicks-prevTicks;
  prevTicks = currTicks;
  return ticks;
}

int Clock::getFps() const { 
  if ( getSeconds() > 0 ) return frames/getSeconds();  
  else if ( getTicks() > 1000 and getFrames() == 0 ) {
    throw std::string("Can't getFps if you don't increment the frames");
  }
  else return 0;
}

Clock& Clock::operator++() { 
  if ( !paused ) ++frames; 
  return *this;
}
Clock  Clock::operator++(int) { 
  if ( !paused ) frames++; 
  return *this;
}

void Clock::start() { 
  started = true; 
  paused = false; 
  frames = 0;
  timeAtPause = timeAtStart = SDL_GetTicks(); 
}
void Clock::pause() {
  if( started && !paused ) {
    timeAtPause = SDL_GetTicks() - timeAtStart;
    paused = true;
  }
}
void Clock::unpause() {
  if( started && paused ) {
    timeAtStart = SDL_GetTicks() - timeAtPause;
    paused = false;
  }
}

