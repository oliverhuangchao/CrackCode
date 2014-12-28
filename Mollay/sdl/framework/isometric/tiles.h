#include <string>
#include <vector>
#include "sprite.h"

class Tiles : public Drawable {
public:
  Tiles(const std::string&);  
  Tiles(const Tiles& s); // canonical form
  ~Tiles();

  virtual void draw() const;
  virtual void update(Uint32) {} // tiles don't move
  virtual const Frame* getFrame() const { return floorFrame; }

private:
  SDL_Surface * floorSurface;
  Frame * floorFrame;
  std::vector< std::vector<Sprite> > floor;

  SDL_Surface * wallSurface;
  Frame * wallFrame;
  int frameWidth;
  int frameHeight;
  int worldWidth;
  int worldHeight;
  Tiles& operator=(const Tiles&); 
};
