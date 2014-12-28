#include <sstream>
#include "lights.h"
#include "gamedata.h"
#include "ioManager.h"

Lights::Lights( ) :
  gdata( Gamedata::getInstance() ),
  screen( IOManager::getInstance().getScreen() ),
  viewWidth( gdata->getXmlInt("viewWidth") ),
  viewHeight( gdata->getXmlInt("viewHeight") ),
  diffuseGridX( gdata->getXmlInt("diffuseGridX") ),
  diffuseGridY( gdata->getXmlInt("diffuseGridY") ),
  lights()
{
  addLights();
}

Lights::~Lights( ) {
  std::cout << "Putting out the lights ..." << std::endl;
  std::list<Light*>::iterator ptr = lights.begin();
  while ( ptr != lights.end() ) {
    delete (*ptr);
    ++ptr;
  }
}

void Lights::addLight(const Triple& triple, int brightness) {
  lights.push_back(new Light( triple, brightness ) );
}

void Lights::addLights( ) {
  std::string thisLight("light");
  unsigned int numberOfLights = gdata->getXmlInt("numberOfLights");
  for (unsigned int i = 0; i < numberOfLights; ++i) {
    std::stringstream strm;
    strm << i+1;
    int x = gdata->getXmlInt(thisLight+"X"+strm.str());
    int y = gdata->getXmlInt(thisLight+"Y"+strm.str());
    int z = gdata->getXmlInt(thisLight+"Z"+strm.str());
    addLight( Triple(x, y, z), gdata->getXmlInt("brightness") );
  }
}

void Lights::draw( ) const {
  Light::drawIllumination(screen, lights, 
    viewWidth, viewHeight, diffuseGridX, diffuseGridY
  );
}

void Lights::update( ) const {
  std::list<Light*>::const_iterator ptr = lights.begin();
  while ( ptr != lights.end() ) {
    (*ptr)->update();
    ++ptr;
  }
}
