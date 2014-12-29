#include <SDL.h>
#include "ioManager.h"
#include "clock.h"
#include "sprite.h"
#include "tiles.h"

class Manager {
public:
  Manager ();
  ~Manager ();
  void play();

private:
  const bool env;
  const IOManager& io;
  Clock& clock;

  SDL_Surface * const screen;
  int backRed;
  int backGreen;
  int backBlue;

  SDL_Surface* orbSurface;
  const Frame * const orbFrame;
  Sprite orb;
  bool makeVideo;
  int frameCount;
  int frameMax;
  const std::string TITLE;

  Tiles tiles;

  void draw() const;
  void update();

  Manager(const Manager&);
  Manager& operator=(const Manager&);
  void drawBackground() const;
};
