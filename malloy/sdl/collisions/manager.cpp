#include <iostream>
#include <string>
#include "gamedata.h"
#include "manager.h"
#include "multisprite.h"
#include "rotscaledMultisprite.h"

Uint32 getPixel32( SDL_Surface *surface, int x, int y ) {
  Uint32 *pixels = static_cast<Uint32 *>(surface->pixels);
  return pixels[ ( y * surface->w ) + x ];
}

Manager::~Manager() { 
  // These deletions eliminate "definitely lost" and
  // "still reachable"s in Valgrind.
  for (unsigned i = 0; i < sprites.size(); ++i) {
    delete sprites[i];
  }
}

Manager::Manager() :
  env( SDL_putenv(const_cast<char*>("SDL_VIDEO_CENTERED=center")) ),
  io( IOManager::getInstance() ),
  clock( Clock::getInstance() ),
  screen( io.getScreen() ),
  world("back", Gamedata::getInstance().getXmlInt("back/factor") ),
  viewport( Viewport::getInstance() ),
  player("redstar"),
  sprites(),
  mousex(0),
  mousey(0)
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw string("Unable to initialize SDL: ");
  }
  atexit(SDL_Quit);
  sprites.push_back( new RotateScaledMultisprite("rotatebat") );
  sprites.push_back( new MultiSprite("bat") );
  sprites.push_back( new MultiSprite("coin") );
  sprites.push_back( new Sprite("greenorb") );
  sprites.push_back( new Sprite("box") );
  sprites.push_back( new Sprite("box2") );
  sprites.push_back( new Sprite("pter") );
  sprites.push_back( new Sprite("spiral") );
  viewport.setObjectToTrack(player.getSprite());
}

void Manager::printPixels( int x, int y ) const {
  SDL_Surface *surface = IOManager::getInstance().getScreen();
  SDL_LockSurface(surface);
  Uint32 pixel = getPixel32(surface, x, y);
  Uint8 red, green, blue;
  SDL_GetRGB(pixel, surface->format, &red, &green, &blue);
  std::stringstream strm;
  strm << "(r, g, b) = (" 
       << static_cast<int>(red) << ", "
       << static_cast<int>(green) << ", "
       << static_cast<int>(blue) << ')' 
       << std::ends;
  SDL_UnlockSurface(surface);
  IOManager::getInstance().printMessageAt(strm.str(), 10, 420);
  //strm.str("");
  //strm << "pixel: " << pixel << std::ends;
  //IOManager::getInstance().printMessageAt(strm.str(), 10, 440);
}

bool Manager::checkForCollisions() const {
  std::vector<Drawable*>::const_iterator sprite = sprites.begin();
  while ( sprite != sprites.end() ) {
    if ( player.collidedWith(*sprite) ) return true;
    ++sprite;
  }
  return false;
}

void Manager::draw(int mouseX, int mouseY) const {
  world.draw();
  for (unsigned i = 0; i < sprites.size(); ++i) {
    sprites[i]->draw();
  }
  player.draw();

  io.printMessageValueAt("seconds: ", clock.getSeconds(), 10, 110);
  io.printMessageValueAt("fps: ", clock.getFps(), 10, 130);
  io.printMessageAt("1. Mid-Distance Strategy", 10, 10);
  io.printMessageAt("2. Rectangle Strategy", 10, 30);
  io.printMessageAt("3. Per-Pixel  Strategy", 10, 50);

  io.printMessageAt("b = rotate bat", 320, 445);

  std::stringstream strm;
  int playerX = static_cast<int>(player.getX());
  int playerY = static_cast<int>(player.getY());
  strm << "Player at: (" << playerX << ", " << playerY << ")";
  io.printMessageAt(strm.str(), 320, 10);

  if ( checkForCollisions() ) {
    io.printMessageAt("*** Oops ***, collision!", 320, 60);
    io.printMessageAt("***", playerX-viewport.X(), playerY-viewport.Y()-10);
    io.printMessageAt("***", playerX-viewport.X(), playerY-viewport.Y()+20);
  }
  else {
    io.printMessageAt("No Collision.", 320, 60);
  }
  strm.str("");
  strm << "Mouse: (" << mouseX << ", " << mouseY << ")" << std::ends;
  io.printMessageAt(strm.str(), 10, 400);

  printPixels(mouseX, mouseY);
}

void Manager::update() {
  ++clock;
  Uint32 ticks = clock.getElapsedTicks();
  for (unsigned int i = 0; i < sprites.size(); ++i) {
    sprites[i]->update(ticks);
  }
  world.update();
  player.update(ticks);
  player.stop();
  viewport.update(); // always update viewport last
}

void Manager::play() {
  SDL_Event event;

  bool done = false;
  bool keyCatch = false;
  while ( not done ) {

    SDL_PollEvent(&event);
    Uint8 *keystate = SDL_GetKeyState(NULL);
    if (event.type ==  SDL_QUIT) { done = true; break; }
    if(event.type == SDL_KEYUP) { 
      keyCatch = false; 
    }
    if(event.type == SDL_KEYDOWN) {
      if (keystate[SDLK_ESCAPE] || keystate[SDLK_q]) {
        done = true;
        break;
      }
      if (keystate[SDLK_1]) {
        player.setCollisionStrategy(0);
      }
      if (keystate[SDLK_2]) {
        player.setCollisionStrategy(1);
      }
      if (keystate[SDLK_3]) {
        player.setCollisionStrategy(2);
      }

      if (keystate[SDLK_s] && !keyCatch) {
        keyCatch = true;
        clock.toggleSloMo();
      }
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
      mousex = event.button.x; mousey = event.button.y;
    }
    if (keystate[SDLK_LEFT]) {
      player.left();
    }
    if (keystate[SDLK_RIGHT]) {
      player.right();
    }
    if (keystate[SDLK_UP]) {
      player.up();
    }
    if (keystate[SDLK_DOWN]) {
      player.down();
    }

    if (keystate[SDLK_b] && !keyCatch) {
      keyCatch = true; 
      static_cast<RotateScaledMultisprite*>(sprites[0])->rotate();
    }

    draw(mousex, mousey);
    SDL_Flip(screen);

    update();
  }
}
