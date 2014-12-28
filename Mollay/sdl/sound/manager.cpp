#include <cstdlib>
#include <cmath>
#include "manager.h"

Manager::~Manager () { }

Manager::Manager() :
  cur_ticks(0), prev_ticks(0), ticks(0),
  sound(),
  io( IOManager::getInstance() ),
  screen( io.getScreen() )
  {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
     throw string("Unable to initialize SDL: ");
    }
    atexit(SDL_Quit);
    SDL_WM_SetCaption( "*** SDL Wave Sound Demo ***", NULL );
}

bool Manager::checkNumber(const std::string& number) const {
  if (number.size() > 1) return false;
  if (number[0] >= '0' && number[0] < '6') return true;
  return false;
}

void Manager::drawBackground() const {
  SDL_FillRect( screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255) );
  SDL_Rect dest = {0, 0, 0, 0};
  SDL_BlitSurface( screen, NULL, screen, &dest );
}

void Manager::play() {
  int frames = 0;
  int fps = 0;
  SDL_Event event;
  cur_ticks = SDL_GetTicks();
  std::string msg("Type your selection <return>: ");

  bool done = false;
  bool keyCatch = false;
  while ( not done ) {
    prev_ticks = cur_ticks;
    cur_ticks = SDL_GetTicks();
    ticks = cur_ticks-prev_ticks;

    drawBackground();
    ++frames;
    fps = frames/(0.001*cur_ticks);
    io.printMessageValueAt("fps: ", fps,20,10);
    io.printMessageValueAt("seconds: ", SDL_GetTicks()/1000, 20, 30);

    io.printMessageCenteredAt("SDL Sound Player", 50);
    io.printMessageAt("To toggle music: <space>", 20, 110);

    io.printMessageAt("0. Boom", 20, 160);
    io.printMessageAt("1. Gun", 20, 180);
    io.printMessageAt("2. Thump", 20, 200);
    io.printMessageAt("3. Phaser", 20, 220);
    io.printMessageAt("4. Putt Putt", 20, 240);
    io.printMessageAt("5. Explosion", 20, 260);
    io.printMessageAt("6. Cannon   ", 20, 280);
    io.printMessageAt("7. Intro Music", 20, 300);

    SDL_PollEvent(&event);
    if (event.type ==  SDL_QUIT) { break; }
    if(event.type == SDL_KEYDOWN) {
      switch ( event.key.keysym.sym ) {
        case SDLK_ESCAPE : done = true; break;
        case SDLK_q      : done = true; break;
        case SDLK_SPACE      : {
          if (!keyCatch) {
            keyCatch = true;
            io.clearString();
            sound.toggleMusic();
          }
          break;
        }
        case SDLK_0 : case SDLK_1 : case SDLK_2 : case SDLK_3 : 
        case SDLK_4 : case SDLK_5 : case SDLK_6 : case SDLK_7 : {
          if (!keyCatch) {
            keyCatch = true;
            io.clearString();
            io.buildString(event);
            int n = event.key.keysym.sym - SDLK_0;
            sound[n];
            break;
          }
        case SDLK_RETURN      : {
            // Do nothing here!
          }
          default          : { 
            if (!keyCatch) {
              keyCatch = true;
              io.buildString(event);
              break;
            }
          }
        }
      }
    }
    if(event.type == SDL_KEYUP) { keyCatch = false; }
    io.printStringAfterMessage(msg, 20, 90);
    SDL_Flip(screen);
  }
}
