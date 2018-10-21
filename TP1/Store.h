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
typedef void (Store::*fcn_ptr)(const string& name, ostream& s);
typedef std::map<string, fcn_ptr> Request;

private:
  File mediaFolder;
  Folder groupFolder;
  Request requests;

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

  void playElement(const string& name, ostream& s);

  void deleteElement(const string& name);

  void deleteGroup(const string& name);

  Smt createMult(const string& clss, istream& is);

  bool save(const string& outputName );

  bool load(const string& inputName);

  bool processRequest(const string& name, ostream &os);

};

#endif // STORE_H