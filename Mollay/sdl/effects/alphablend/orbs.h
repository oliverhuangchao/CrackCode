#include "sprite.h"
#include "gamedata.h"
#include <vector>

class Orbs {
public:
  Orbs();
  ~Orbs();
  void draw() const;
  void update(Uint32 ticks);
  const Sprite* operator[](int index) { return &orbs[index]; }
  unsigned size() const { return orbs.size(); }
private:
  const Gamedata* gdata;
  SDL_Surface * const orbSurface;
  Frame * const orbFrame;
  std::vector<Sprite> orbs;
  Orbs(const Orbs&);
  Orbs& operator=(const Orbs&);
};
