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
using Sst = std::shared_ptr<Store>;


class Creational{
public:
  static Smt createMult(const string &clss, istream &is, Sst store){
    string name;
    if (clss.compare("Photo") == 0){
      getline(is,name);
      return store->createPhoto(name);
    }else if (clss.compare("Video") == 0){
      getline(is,name);
      return store->createVideo(name);
    }else if (clss.compare("Film") == 0){
      getline(is,name);
      return store->createFilm(name);
    }else 
      return nullptr;
  }
};
#endif