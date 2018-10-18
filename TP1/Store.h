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
  File mediaFolder;
  Folder groupFolder;

public:
  Store();

  ~Store();
  
  Smt createPhoto(const string& name, 
    const string& path, double latitude, double longitude);

  Smt createPhoto(const string& name);

  Smt createVideo(const string& name, 
    const string& path, double duration);
  
  Smt createVideo(const string& name);

  Smt createFilm(const string& name, 
    const string& path, int duration, int size, const int *chapter);    
  
  Smt createFilm(const string& name);

  Sgr createGroup(const string& name);

  void showElement(const string& name, ostream& s );

  void playElement(const string& name);

  void deleteElement(const string& name);

  void deleteGroup(const string& name);

};

#endif // STORE_H