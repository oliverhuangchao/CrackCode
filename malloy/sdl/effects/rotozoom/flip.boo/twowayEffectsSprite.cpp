#include <iostream>
#include <cmath>
#include "twowayEffectsSprite.h"
#include "gamedata.h"
#include "SDL/SDL_rotozoom.h"

void TwowayEffectsSprite::advanceFrame(Uint32 ticks) {
  float ms = 1000.0/frameInterval;
  dt += ticks;
  int df = dt / ms;
  dt -= df * ms;
  currentFrame = (currentFrame + df) % numberOfFrames;
}

TwowayEffectsSprite::TwowayEffectsSprite( const std::string& name, 
                  Frame* fm) :
  Drawable(name, 
           Vector2f(Gamedata::getInstance()->getXmlInt(name+"X"), 
                    Gamedata::getInstance()->getXmlInt(name+"Y")), 
           Vector2f(Gamedata::getInstance()->getXmlInt(name+"SpeedX"),
                    Gamedata::getInstance()->getXmlInt(name+"SpeedY"))
           ),
  frame(fm),
  booRight(true),
  frameWidth(frame->getWidth()),
  frameHeight(frame->getHeight()),
  worldWidth(Gamedata::getInstance()->getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance()->getXmlInt("worldHeight")),
  dt(0),
  currentFrame(0),
  numberOfFrames( Gamedata::getInstance()->getXmlInt(name+"Frames") ),
  frameInterval( Gamedata::getInstance()->getXmlInt(name+"FrameInterval") )
{ 
   SDL_Surface* surface = frame->getSurface();
  // params: (surface, angle, zoomz, zoomy, smooth)
  // surface = rotozoomSurfaceXY(surface, 0, 1, -1, SMOOTHING_ON);
  // frame->setSurface(surface);
}

TwowayEffectsSprite::
TwowayEffectsSprite(const TwowayEffectsSprite& s) :
  Drawable(s.getName(), s.getPosition(), s.getVelocity()),
  frame(s.frame),
  booRight(s.booRight),
  frameWidth(s.frameWidth),
  frameHeight(s.frameHeight),
  worldWidth(s.worldWidth),
  worldHeight(s.worldHeight),
  dt(s.dt),
  currentFrame(s.currentFrame),
  numberOfFrames( s.numberOfFrames ),
  frameInterval( s.frameInterval )
  { }

void TwowayEffectsSprite::draw() const { 
  Uint32 x = static_cast<Uint32>(X());
  Uint32 y = static_cast<Uint32>(Y());
  frame->draw(currentFrame*frameWidth, 0, x, y);
}

// SDL_Surface* zoomSurface(SDL_Surface* src, 
//               double zoomx, double zoomy, int smooth);
//  zooms a 32bit or 8bit 'src' surface to newly created 'dst' surface.  
//  'zoomx' and 'zoomy' are scaling factors for width and height. 
//  If 'smooth' is 1 then the destination 32bit surface is anti-aliased. 
//  If the surface is not 8bit or 32bit RGBA/ABGR it will 
//  be converted into a 32bit RGBA format on the fly. 
void TwowayEffectsSprite::update(Uint32 ticks) { 
  advanceFrame(ticks);

  Vector2f incr = getVelocity() * static_cast<float>(ticks) * 0.001;
  setPosition(getPosition() + incr);

  if ( Y() < 0) {
    velocityY( abs( velocityY() ) );
  }
  if ( Y() > worldHeight-frameHeight) {
    velocityY( -abs( velocityY() ) );
  }

  if ( X() < 0) {
    velocityX( abs( velocityX() ) );
  }
  if ( X() > worldWidth-frameWidth) {
    velocityX( -abs( velocityX() ) );
  }  

  if ( velocityX() < 0 && booRight ) {
    booRight = false;
    SDL_Surface* surface = frame->getSurface();
    SDL_Surface* pic = zoomSurface(surface, -1, 1, SMOOTHING_ON);
    if ( pic != NULL ) {
      SDL_FreeSurface(surface);
      frame->setSurface(pic);
    }
    else throw "zoomSurface failed in TwowayEffectsSprite";
  }
  if ( velocityX() > 0 && !booRight) {
    booRight = true;
    SDL_Surface* surface = frame->getSurface();
    SDL_Surface* pic = zoomSurface(surface, -1, 1, SMOOTHING_ON);
    if ( pic != NULL ) {
      SDL_FreeSurface(surface);
      frame->setSurface(pic);
    }
    else throw "zoomSurface failed in TwowayEffectsSprite";
  }
}
