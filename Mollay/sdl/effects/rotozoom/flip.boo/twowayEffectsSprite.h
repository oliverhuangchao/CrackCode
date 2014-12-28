#ifndef TWOWAY_EFFECTSSPRITE__H
#define TWOWAY_EFFECTSSPRITE__H

#include <string>
#include <iostream>
#include <vector>
#include "drawable.h"

class TwowayEffectsSprite : public Drawable {
public:
  TwowayEffectsSprite(const std::string& n, Frame* fm);
  TwowayEffectsSprite(const TwowayEffectsSprite& s);
  virtual ~TwowayEffectsSprite() { } 
  virtual const Frame* getFrame() const { return frame; }

  virtual void draw() const;
  virtual void update(Uint32 ticks);

private:
  Frame * frame;
  bool booRight;
  int frameWidth;
  int frameHeight;
  int worldWidth;
  int worldHeight;
  float dt;
  unsigned currentFrame;
  unsigned numberOfFrames;
  unsigned frameInterval;
  void advanceFrame(Uint32 ticks);
  TwowayEffectsSprite& operator=(const TwowayEffectsSprite&);
};
#endif
