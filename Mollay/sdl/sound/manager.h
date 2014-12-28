// Brian Malloy        September, 2007
// Framework for Game Engine

#include <SDL/SDL.h>
#include <string>
#include "frame.h"
#include "sound.h"

class Manager {
public:
  Manager();
  ~Manager();
  void play();

private:
  Uint32 cur_ticks;
  Uint32 prev_ticks;
  Uint32 ticks;
  SDLSound sound;

  IOManager& io;
  SDL_Surface *screen;
  bool checkNumber(const std::string&) const;
  void drawBackground() const;
  Manager(const Manager&);
  Manager& operator=(const Manager&);
};
