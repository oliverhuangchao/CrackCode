#include <cmath>
#include "manager.h"

Manager::~Manager() { 
  // These deletions eliminate "definitely lost" and
  // "still reachable"s in Valgrind.
  SDL_FreeSurface(orbSurface);
  SDL_Surface* surface = booFrame->getSurface();
  SDL_FreeSurface(surface);
  delete orbFrame;
  delete booFrame;
  delete Gamedata::getInstance();
}

Manager::Manager() :
  env( SDL_putenv(const_cast<char*>("SDL_VIDEO_CENTERED=center")) ),
  gdata( Gamedata::getInstance() ),
  io( IOManager::getInstance() ),
  clock( Clock::getInstance() ),
  screen( io.getScreen() ),
  backRed( gdata->getXmlInt("backRed") ),
  backGreen( gdata->getXmlInt("backGreen") ),
  backBlue( gdata->getXmlInt("backBlue") ),

  booSurface( io.loadAndSet(gdata->getXmlStr("booFile"), 
                gdata->getXmlBool("booTransparency")) ),
  booFrame(new Frame(booSurface,
                gdata->getXmlInt("booWidth"), 
                gdata->getXmlInt("booHeight"), 
                gdata->getXmlInt("booSrcX"), 
                gdata->getXmlInt("booSrcY")) 
  ),
  boo("boo", booFrame),

  orbSurface( io.loadAndSet(gdata->getXmlStr("redorbFile"), 
                gdata->getXmlBool("redorbTransparency")) ),
  orbFrame(new Frame(orbSurface,
                gdata->getXmlInt("redorbWidth"), 
                gdata->getXmlInt("redorbHeight"), 
                gdata->getXmlInt("redorbSrcX"), 
                gdata->getXmlInt("redorbSrcY")) 
  ),
  orb("redorb", orbFrame)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw string("Unable to initialize SDL: ");
  }
  atexit(SDL_Quit);
}

void Manager::drawBackground() const {
  SDL_FillRect( screen, NULL, 
    SDL_MapRGB(screen->format, backRed, backGreen, backBlue) );
  SDL_Rect dest = {0, 0, 0, 0};
  SDL_BlitSurface( screen, NULL, screen, &dest );
}

void Manager::draw() const {
  drawBackground();
  io.printMessageCenteredAt("Using Rotozoom for a two-way Sprite", 20);
  orb.draw();
  boo.draw();
}

void Manager::play() {
  SDL_Event event;

  bool done = false;
  bool keyCatch = false;
  while ( not done ) {
    draw();
    SDL_Flip(screen);

    Uint32 ticks = clock.getElapsedTicks();
    orb.update(ticks);
    boo.update(ticks);

    SDL_PollEvent(&event);
    if (event.type ==  SDL_QUIT) { break; }
    if(event.type == SDL_KEYUP) { keyCatch = false; }
    if(event.type == SDL_KEYDOWN) {
      switch ( event.key.keysym.sym ) {
        case SDLK_ESCAPE : done = true; break;
        case SDLK_q      : done = true; break;
        case SDLK_p      : {
          if (!keyCatch) {
            keyCatch = true;
            if ( clock.isPaused() ) clock.unpause();
            else clock.pause();
          }
          break;
        }
        default          : break;
      }
    }
  }
}
