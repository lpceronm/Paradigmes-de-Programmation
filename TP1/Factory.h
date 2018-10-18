#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"


using namespace std;
using Smt = std::shared_ptr<Multimedia>;

class Creational{
public:
  static Multimedia* createMult(const string &clss)
  {
    if (clss.compare("Photo") == 0)
      return new Photo();
    else if (clss.compare("Video") == 0)
      return new Video;
    else if (clss.compare("Film") == 0)
      return new Film;
    else 
      return nullptr;
  }
};
#endif