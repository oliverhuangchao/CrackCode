#include <SDL.h>
#include <iostream>
#include <string>

#include "ioManager.h"
#include "clock.h"
#include "world.h"

#include "orbs.h"

class Manager {
public:
  Manager ();
  ~Manager ();
  void play();

private:
  const bool env;
  const Gamedata* gdata;
  const IOManager& io;
  Clock& clock;

  SDL_Surface *screen;
  SDL_Surface * const bgSurface;
  const Frame background;
  SDL_Surface * const fgSurface;
  Frame foreground;
  Orbs orbs;
  int objTracking;
  float alpha;
  World backWorld;
  World frontWorld;
  Viewport& view;

  Manager(const Manager&);
  Manager& operator=(const Manager&);
};
