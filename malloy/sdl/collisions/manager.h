#include <vector>
#include <SDL.h>
#include "ioManager.h"
#include "clock.h"
#include "player.h"
#include "world.h"
#include "viewport.h"

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

  World world;
  Viewport& viewport;
  Player player;

  std::vector<Drawable*> sprites;
  int mousex, mousey;

  void printPixels( int, int ) const;
  void draw(int, int) const;
  bool checkForCollisions() const;
  void update();
  Manager(const Manager&);
  Manager& operator=(const Manager&);
};
