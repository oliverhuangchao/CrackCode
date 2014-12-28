// Brian Malloy        2013
#include <SDL_mixer.h>
#include "manager.h"

int main() {
   try {
      Manager* game_manager = new Manager();
      game_manager->play();
      delete  game_manager;
   }
   catch (const string& msg) { std::cout << msg << std::endl; }
   catch (...) {
      std::cout << "Oops, someone threw an exception!" << std::endl;
   }
   return 0;
}
