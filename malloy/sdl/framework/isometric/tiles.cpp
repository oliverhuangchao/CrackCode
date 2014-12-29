#include <iostream>
#include <cmath>
#include "tiles.h"
#include "gamedata.h"
#include "ioManager.h"

Tiles::~Tiles() {
  SDL_FreeSurface(floorSurface);
  SDL_FreeSurface(wallSurface);
  delete wallFrame;
  delete floorFrame;
}

Tiles::Tiles(const std::string& name) :
  Drawable(name,
           Vector2f(Gamedata::getInstance().getXmlInt(name+"X"), 
                    Gamedata::getInstance().getXmlInt(name+"Y")), 
           Vector2f(Gamedata::getInstance().getXmlInt(name+"SpeedX"), 
                    Gamedata::getInstance().getXmlInt(name+"SpeedY")) 
           ),
  floorSurface(
    IOManager::getInstance().
    loadAndSet(Gamedata::getInstance().getXmlStr(name+"File"), false)
  ),
  floorFrame( new Frame(name, floorSurface) ),
  floor(),

  wallSurface(
    IOManager::getInstance().
    loadAndSet(Gamedata::getInstance().getXmlStr("wallFile"), false)
  ),
  wallFrame( new Frame("wall", wallSurface) ),

  frameWidth(floorFrame->getWidth()),
  frameHeight(floorFrame->getHeight()),
  worldWidth(Gamedata::getInstance().getXmlInt("worldWidth")),
  worldHeight(Gamedata::getInstance().getXmlInt("worldHeight"))
{ }

void Tiles::draw() const { 
  // Draw the floor:
  int k = 0;
  for (unsigned int j = 0; j < 480; j += 16) {
    if (k) k = 0; else k = 32;
    for (unsigned int i = k; i < 608; i+=64) {
      floorFrame->draw(i, j); 
    }
  }
  // Draw a wall:
  k = 64;
  for (unsigned int i = 248; i > 56; i-=32) {
    wallFrame->draw(i, k); 
    k += 16;
  }
}
