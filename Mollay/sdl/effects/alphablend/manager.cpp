#include <cmath>
#include <sstream>
#include "manager.h"

Manager::~Manager() { 
  // These deletions eliminate "definitely lost" and
  // "still reachable"s in Valgrind.
  SDL_FreeSurface(bgSurface);
  delete Gamedata::getInstance();
}

Manager::Manager() :
  env( SDL_putenv(const_cast<char*>("SDL_VIDEO_CENTERED=center")) ),
  gdata( Gamedata::getInstance() ),
  io( IOManager::getInstance() ),
  clock( Clock::getInstance() ),
  screen( io.getScreen() ),
  bgSurface( io.loadAndSet(gdata->getXmlStr("citybackFile"), false) ),
  background(bgSurface,
             gdata->getXmlInt("citybackWidth"), 
             gdata->getXmlInt("citybackHeight"), 
             gdata->getXmlInt("citybackSrcX"),
             gdata->getXmlInt("citybackSrcY")),
  fgSurface( io.loadAndSet(gdata->getXmlStr("cityfrontFile"), false) ),
  foreground(fgSurface,
             gdata->getXmlInt("cityfrontWidth"), 
             gdata->getXmlInt("cityfrontHeight"), 
             gdata->getXmlInt("cityfrontSrcX"),
             gdata->getXmlInt("cityfrontSrcY")),
  orbs(),
  objTracking(0),
  alpha( SDL_ALPHA_OPAQUE ),
  backWorld(&background, 2),
  frontWorld(&foreground),
  view(Viewport::getInstance())
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw string("Unable to initialize SDL: ");
  }
  view.setObjectToTrack(orbs[objTracking]);
  atexit(SDL_Quit);
}

void Manager::play() {
  SDL_Event event;

  bool done = false;
  bool keyCatch = false;
  while ( not done ) {
    backWorld.draw();
    frontWorld.draw();
    orbs.draw();

    std::stringstream strm;
    strm << "Alpha value: " << static_cast<int>(alpha) << "\0";
    io.printMessageAt(strm.str(), 10, 10);

    strm.clear(); // clear error flags
    strm.str(std::string()); // clear contents
    strm << "Tracking orb #" << objTracking << "\0";
    io.printMessageAt(strm.str(), 10, 30);

    SDL_Flip(screen);

    Uint32 ticks = clock.getElapsedTicks();
    orbs.update(ticks);
    backWorld.update();
    frontWorld.update();
    view.update();

    SDL_PollEvent(&event);
    if (event.type ==  SDL_QUIT) { break; }
    if(event.type == SDL_KEYUP) { keyCatch = false; }
    if(event.type == SDL_KEYDOWN) {
      switch ( event.key.keysym.sym ) {
        case SDLK_ESCAPE : done = true; break;
        case SDLK_q      : done = true; break;
        case SDLK_t :
          if ( !keyCatch ) {
            keyCatch = true;
            objTracking = (objTracking+1) % orbs.size(); 
            view.setObjectToTrack(orbs[objTracking]);
          }
          break;
        case SDLK_DOWN      : {
          if( alpha > SDL_ALPHA_TRANSPARENT ) {
            alpha -= 0.1;
            //SDL_SetAlpha( fgSurface, SDL_SRCALPHA | SDL_RLEACCEL, alpha );
            foreground.setAlpha(alpha);
          }
          break;
        }
        case SDLK_UP      : {
          if( alpha < SDL_ALPHA_OPAQUE ) {
            alpha += 0.1;
            //SDL_SetAlpha( fgSurface, SDL_SRCALPHA | SDL_RLEACCEL, alpha );
            foreground.setAlpha(alpha);
          }
          break;
        }
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
