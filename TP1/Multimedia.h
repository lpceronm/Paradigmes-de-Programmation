#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <iostream>
using namespace std;

class Multimedia{
private:
  string name = "";
  string path = "";

public:
  Multimedia();
  Multimedia(string name, string path) : name(name), path(path) {}
  void setName(string name) { name = name; }
  void setPath(string path) { path = path; }
  string getName() const { return name; }
  string getPath() const { return path; }
  virtual void show(ostream &);
  ~Multimedia();
};

#endif // MULTIMEDIA_H
