#ifndef STORE_H
#define STORE_H

#include <memory>
#include <map>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"

typedef std::map<string, Smt> File; 
typedef std::map<string, Group> Folder; 

class Store{

private:
  File mediaFile;
  Folder groupFolder;

public:
  Store();

  Smt createPhoto(const string& storeName,const string& name, const string& path, double latitude, double longitude);


};

#endif // STORE_H