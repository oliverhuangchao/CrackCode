// An example of changing an image with SDL & rotozoom.

// SDL_Surface* zoomSurface(SDL_Surface* src, 
//               double zoomx, double zoomy, int smooth);
//  zooms a 32bit or 8bit 'src' surface to newly created 'dst' surface.  
//  'zoomx' and 'zoomy' are scaling factors for width and height. 
//  If 'smooth' is 1 then the destination 32bit surface is anti-aliased. 
//  If the surface is not 8bit or 32bit RGBA/ABGR it will 
//  be converted into a 32bit RGBA format on the fly. 

 
// SDL_Surface * rotozoomSurface (SDL_Surface *src, double angle, 
//               double zoom, int smooth);
//  Rotates and zooms a 32bit or 8bit 'src' surface to newly created 'dst' 
//  surface.  'angle' is the rotation in degrees. 'zoom' a scaling factor. 


#include <SDL/SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <sstream>
#include "SDL/SDL_rotozoom.h"
#include "ioManager.h"

void drawBackground() {
  SDL_Surface* screen = IOManager::getInstance().getScreen();
  // Drawing a white background
  SDL_FillRect( screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255) );
  SDL_Rect dest = {0, 0, 0, 0};
  SDL_BlitSurface( screen, NULL, screen, &dest );
}

void draw(SDL_Surface* image, double zoom, double angle) {
  IOManager& io = IOManager::getInstance();
  SDL_Surface* screen = io.getScreen();
  drawBackground();
  io.printMessageAt("Up/Down arrow to zoom: ", 400, 20);
  io.printMessageAt("Left/Right arrow to flip: ", 400, 40);
  io.printMessageValueAt("Zoom value: ", zoom, 400, 60);
  io.printMessageValueAt("Angle value: ", angle, 400, 80);
  // Check out definitions for SDL_Rect and SDL_BlitSurface
  SDL_Rect src = { 0, 0, image->w, image->h };
  // The last two arguments to destination rect are meaningless:
  SDL_Rect dest = {10, 10, 0, 0 };
  SDL_BlitSurface(image, &src, screen, &dest);
  SDL_Flip(screen);
}

int main() {
  try {
    SDL_putenv(const_cast<char*>("SDL_VIDEO_CENTERED=center"));

    SDL_Surface *pter = 
      IOManager::getInstance().loadAndSet("images/pter.bmp", true);
    SDL_Surface *pic;
    if (pter == NULL) { throw string("Unable to load pter."); }
    double zoom = 1.0;
    double angle = 0.0;
    if ((pic=zoomSurface(pter, zoom, zoom, SMOOTHING_ON))==NULL) {
      throw ("Unable to zoom surface on line "+__LINE__);
    }

    bool keyCatch = false;
    SDL_Event event; 
    bool done = false;
    while ( not done ) {
      draw(pic, zoom, angle);

      SDL_PollEvent(&event);
      Uint8 *keystate = SDL_GetKeyState(NULL);
      if (event.type ==  SDL_QUIT) { break; }
      if(event.type == SDL_KEYUP) { keyCatch = false; }
      if(event.type == SDL_KEYDOWN) {
        switch ( event.key.keysym.sym ) {
          case SDLK_ESCAPE : done = true; break;
          case SDLK_q      : done = true; break;
          default          : break;
        }
        if ((keystate[SDLK_MINUS] || keystate[SDLK_DOWN]) && zoom > 0.3) {
          if (keyCatch) continue;
          keyCatch = true;
          zoom -= 0.1;
          // Free the surface to avoid memory leaks:
          SDL_FreeSurface(pic);
          pic = zoomSurface(pter, zoom, zoom, SMOOTHING_ON);
          if ( pic == NULL) {
            throw ("Unable to zoom surface on line "+__LINE__);
          }
        }
        if ((keystate[SDLK_EQUALS] || keystate[SDLK_UP]) && zoom < 4.0) {
          if (keyCatch) continue;
          keyCatch = true;
          zoom += 0.1;
          // Free the surface to avoid memory leaks:
          SDL_FreeSurface(pic);
          pic = zoomSurface(pter, zoom, zoom, SMOOTHING_ON);
          if ( pic == NULL) {
            throw ("Unable to zoom surface on line "+__LINE__);
          }
        }
        if (keystate[SDLK_RIGHT] && !keyCatch) {
          keyCatch = true;
          angle += 90;
          // Free the surface to avoid memory leaks:
          SDL_FreeSurface(pic);
          pic = rotozoomSurface(pter,angle,zoom,SMOOTHING_ON);
          if ( pic == NULL) {
            throw ("Unable to zoom surface on line "+__LINE__);
          }
        }
        if (keystate[SDLK_LEFT] && !keyCatch) {
          keyCatch = true;
          angle -= 90;
          // Free the surface to avoid memory leaks:
          SDL_FreeSurface(pic);
          pic = rotozoomSurface(pter,angle,zoom,SMOOTHING_ON);
          if ( pic == NULL) {
            throw ("Unable to zoom surface on line "+__LINE__);
          }
        }
      }
    }
    SDL_FreeSurface(pter);
    SDL_FreeSurface(pic);
  }
  catch (const string& msg) { std::cout << msg << std::endl; }
  catch(...) {
    std::cout << "Oops" << std::endl;
  }
}
