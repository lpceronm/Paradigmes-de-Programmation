#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Multimedia{
private:
  string name = "";
  string path = "";

public:
  Multimedia();

  Multimedia(string name, string path) : name(name), path(path) {}

  // ~Multimedia();
  virtual void setName(string name) { name = name; }

  virtual void setPath(string path) { path = path; }

  virtual string getName() const { return name; }

  virtual string getPath() const { return path; }

  virtual void show(ostream &s) = 0 ;

  virtual void play() = 0;

};

#endif // MULTIMEDIA_H
