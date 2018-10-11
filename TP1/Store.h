#ifndef STORE_H
#define STORE_H

#include <memory>
#include <map>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"

using Sgr = std::shared_ptr<Group>;

typedef std::map<string, Smt> File; 
typedef std::map<string, Sgr> Folder; 



class Store{

private:
  File mediaFile;
  Folder groupFolder;

public:
  Store();

  Smt createPhoto(const string& storeName, const string& name, 
    const string& path, double latitude, double longitude);

  Smt createVideo(const string& storeName, const string& name, 
    const string& path, double duration);
  
  Smt createFilm(const string& storeName, const string& name, 
    const string& path, int duration, int size, const int *chapter);    
  
  Sgr createGroup(const string& storeName, const string& name);

};

#endif // STORE_H