#include "orbs.h"
#include "ioManager.h"

Orbs::~Orbs() { 
  SDL_FreeSurface(orbSurface);
  delete orbFrame;
  orbs.clear(); 
}

Orbs::Orbs() :
  gdata( Gamedata::getInstance() ),
  orbSurface( IOManager::getInstance().
              loadAndSet(gdata->getXmlStr("redorbFile"), true) ),
  orbFrame(new Frame(orbSurface,
                gdata->getXmlInt("redorbWidth"), 
                gdata->getXmlInt("redorbHeight"), 0, 0)),
  orbs()
{
  const unsigned minOrbs = Gamedata::getInstance()->getXmlInt("redorbsMin");
  const unsigned maxOrbs = Gamedata::getInstance()->getXmlInt("redorbsMax");
  const int minSpeedX = 
    Gamedata::getInstance()->getXmlInt("redorbsXspeedMin");
  const int maxSpeedX = 
    Gamedata::getInstance()->getXmlInt("redorbsXspeedMax");
  const int minSpeedY = 
    Gamedata::getInstance()->getXmlInt("redorbsYspeedMin");
  const int maxSpeedY = 
    Gamedata::getInstance()->getXmlInt("redorbsYspeedMax");
  unsigned numberOfOrbs = rand() % maxOrbs;
  if ( numberOfOrbs < minOrbs ) numberOfOrbs = minOrbs;
  for (unsigned i = 0; i < numberOfOrbs; ++i) {
    int x = Gamedata::getInstance()->getXmlInt("redorbX")+rand()%100;
    int y = Gamedata::getInstance()->getXmlInt("redorbY");
    int sx = (rand() % (maxSpeedX-minSpeedX)) + minSpeedX;
    int sy = (rand() % (maxSpeedY-minSpeedY)) + minSpeedY;
    sx = sx*(rand()%2?1:-1);
    sy = sy*(rand()%2?1:-1);
    orbs.push_back(
      Sprite(Vector2f(x, y), Vector2f(sx, sy),
             "redorb", orbFrame)
    );
  }
}

void Orbs::draw() const {
  for (unsigned i = 0; i < orbs.size(); ++i) {
    orbs[i].draw();
  }
}

void Orbs::update(Uint32 ticks) {
  for (unsigned i = 0; i < orbs.size(); ++i) {
    orbs[i].update(ticks);
  }
}
