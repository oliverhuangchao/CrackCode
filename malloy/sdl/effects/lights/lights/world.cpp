#include <iostream>
#include "world.h"

World::World(const std::string& name, int fact) : 
  gdata( Gamedata::getInstance() ),
  io( IOManager::getInstance() ),
  surface( io.loadAndSet(gdata->getXmlStr(name+"File"), 
                         gdata->getXmlBool(name+"Transparency") 
                         )
  ),
  frame(new Frame(surface,
              gdata->getXmlInt(name+"Width"), 
              gdata->getXmlInt(name+"Height"), 
              gdata->getXmlInt(name+"SrcX"), 
              gdata->getXmlInt(name+"SrcY"))
  ),
  factor(fact),
    frameWidth( frame->getWidth() ),
    worldWidth( Gamedata::getInstance()->getXmlInt("worldWidth") ),
    viewX(0.0), viewY(0.0), 
    view(Viewport::getInstance()) 
{}

World::~World() {
  SDL_FreeSurface(surface);
  delete frame;
}

void World::update() {
  viewX = static_cast<int>(view.X() / factor) % frameWidth;
  viewY = view.Y();
}

void World::draw() const { 
  frame->draw(viewX, viewY, 0, 0); 
  frame->draw(0, viewY, frameWidth-viewX, 0); 
}

