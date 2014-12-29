#include "ioManager.h"
#include "lsystem.h"
#include "SDL_version.h"

IOManager* IOManager::instance = NULL;

void print_SDL_version(const string& preamble, SDL_version* v) {
  // Tsk, tsk; I'm using printf, which violates Item 2!
  printf("%s %u.%u.%u\n", preamble.c_str(), v->major, v->minor, v->patch);
}

void print_SDL_versions() {
  SDL_version ver;
  SDL_VERSION(&ver);
  print_SDL_version("SDL compile-time version", &ver);
  ver = *SDL_Linked_Version();
  print_SDL_version("SDL runtime version", &ver);
}

void drawBackground(SDL_Surface* screen) {
  SDL_FillRect( screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255) );
  SDL_Rect dest = {0, 0, 0, 0};
  SDL_BlitSurface( screen, NULL, screen, &dest );
}

int main(int argc, char *argv[]) {
  SDL_putenv(const_cast<char*>("SDL_VIDEO_CENTERED=right"));
  SDL_Surface* screen = IOManager::getInstance()->getScreen();
  string filename;
  int steps;
  if ( argc == 1 ) {
    filename = "xmlSpec/square.xml";
    steps = 1;
  }
  else if ( argc == 3 ) {
    filename = argv[1];
    steps = atoi( argv[2] );
  }
  else {
    std::cout << "usage: " << argv[0] << " <filename> <steps>" << std::endl;
    return 0;
  }
  try {
    LSystem ls(filename, steps);
    unsigned currTicks = SDL_GetTicks();
    unsigned prevTicks = currTicks;
    unsigned ticks = 0;

    drawBackground(screen);
    ls.draw();
    SDL_Flip(IOManager::getInstance()->getScreen());

    SDL_Event event;
    while ( true ) {
      prevTicks = currTicks;
      currTicks = SDL_GetTicks();
      ticks = ticks + (currTicks-prevTicks);
      if ( ticks > 1000 ) {
        ls.reset();
        ticks = 0;
      }
      drawBackground(screen);
      ls.draw();
      SDL_Flip(IOManager::getInstance()->getScreen());
      SDL_PollEvent(&event);
      Uint8 *keystate = SDL_GetKeyState(NULL);
      if (event.type ==  SDL_QUIT) { break; }
      if(event.type == SDL_KEYDOWN && keystate[SDLK_ESCAPE]) break;
      if(event.type == SDL_KEYDOWN && keystate[SDLK_q]) break;
    }
    print_SDL_versions();

    delete IOManager::getInstance();
  }
  catch( string & msg ) { cout << msg << endl; }
  catch( std::exception &e ) { cout << e.what() << endl; }
  catch( ... ) { cout << "Oops" << endl; }
  return 0;
}
