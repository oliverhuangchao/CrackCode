#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>

#include "ioManager.h"
#include "clock.h"
#include "gamedata.h"
#include "sprite.h"
#include "twowayEffectsSprite.h"

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
  int backRed;
  int backGreen;
  int backBlue;

  SDL_Surface *booSurface;
  Frame* booFrame;
  TwowayEffectsSprite boo;

  SDL_Surface * const orbSurface;
  Frame * const orbFrame;
  Sprite orb;

  void drawBackground() const;
  void draw() const;
  Manager(const Manager&);
  Manager& operator=(const Manager&);
};
