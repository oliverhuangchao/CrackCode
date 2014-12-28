#ifndef FRAME__H
#define FRAME__H

#include <iostream>
#include <SDL/SDL.h>
#include "ioManager.h"

class Frame {
public:
  // Must pass both width and height here because the sprite might
  // not consist of the whole surface, only part of the surface.
  Frame( SDL_Surface* spr, SDL_Surface* scr,
      Uint16 sprite_width, Uint16 sprite_height,
      Sint16 src_x, Sint16 src_y);
  Frame(const Frame& f) : sprite(f.sprite), screen(f.screen),
    spriteWidth(f.spriteWidth), spriteHeight(f.spriteHeight),
    spriteSourceX(f.spriteSourceX), spriteSourceY(f.spriteSourceY) { }

  void draw(Sint16 x, Sint16 y);

  Uint16 getWidth()  const { return spriteWidth; }
  Uint16 getHeight() const { return spriteHeight; }
  Uint16 getSourceX() const { return spriteSourceX; }
  Uint16 getSourceY() const { return spriteSourceY; }
private:
  SDL_Surface * sprite;
  SDL_Surface * screen;
  Uint16 spriteWidth;
  Uint16 spriteHeight;
  Sint16 spriteSourceX;
  Sint16 spriteSourceY;
};

#endif
