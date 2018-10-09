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

  Multimedia(const string& name, const string& path) : name(name), path(path) {}

  virtual ~Multimedia() = default;

  virtual void setName(const string& set_nam) { name = set_nam; }

  virtual void setPath(const string& set_path) { path = set_path; }

  virtual string getName() const { return name; }

  virtual string getPath() const { return path; }

  virtual void show(ostream &s) = 0 ;

  virtual void play() = 0;

};

#endif // MULTIMEDIA_H
