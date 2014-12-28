#include "SDL/SDL_rotozoom.h"
#include "ioManager.h"
#include "frame.h"
#include "viewport.h"
#include "extractSurface.h"

// The next constructor s/ only be used when the Frames's surface
// starts at (0, 0) in the sprite sheet, and the frame uses the 
// entire sheet. For example, a Frame for an orb or a background.
Frame::Frame( const std::string& name, SDL_Surface* surf ) : 
  screen(IOManager::getInstance().getScreen()),
  width(Gamedata::getInstance().getXmlInt(name+"/width")), 
  height(Gamedata::getInstance().getXmlInt(name+"/height")),
  surface( surf )
{ }

// The next constructor s/ be used when the Frame's surface is
// found on only a part of sprite sheet, width and height is passed:
Frame::Frame( SDL_Surface* surf, Sint16 src_x, Sint16 src_y, 
              Sint16 w, Sint16 h) :
  screen(IOManager::getInstance().getScreen()),
  width(w),
  height(h),
  surface( ExtractSurface::getInstance().
    get(surf, width, height, src_x, src_y) 
  )
{ }

Frame& Frame::operator=(const Frame& rhs) {
  screen = rhs.screen;
  width = rhs.width;
  height = rhs.height;
  surface = ExtractSurface::
    getInstance().get(rhs.surface, rhs.getWidth(), rhs.getHeight(), 0, 0);
  return *this;
}

void Frame::draw(Sint16 x, Sint16 y) const {
  SDL_Rect src = { 0, 0, width, height };    
  x -= Viewport::getInstance().X();
  y -= Viewport::getInstance().Y();
  SDL_Rect dest = {x, y, width, height };
  SDL_BlitSurface(surface, &src, screen, &dest);
}

void Frame::draw(Sint16 sx, Sint16 sy, Sint16 dx, Sint16 dy) const {
  SDL_Rect src = { sx, sy, width, height };    
  SDL_Rect dest = {dx, dy, width, height };
  SDL_BlitSurface(surface, &src, screen, &dest);
}

void Frame::draw(Sint16 x, Sint16 y, double angle) const {
  SDL_Surface* tmp = rotozoomSurface(surface, angle, 1, 1);
  SDL_Rect src = { 0, 0, tmp->w, tmp->h };    
  x -= Viewport::getInstance().X();
  y -= Viewport::getInstance().Y();
  SDL_Rect dest = {x, y, 0, 0 };
  SDL_BlitSurface(tmp, &src, screen, &dest);
  SDL_FreeSurface( tmp );
}
