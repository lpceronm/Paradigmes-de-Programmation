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

  Multimedia(const string& name, const string& path);

  virtual ~Multimedia() = default;

  virtual void setName(const string& set_nam);

  virtual void setPath(const string& set_path);

  virtual string getName() const;

  virtual string getPath() const; 

  virtual void show(ostream &s) = 0 ;

  virtual void play() = 0;

  virtual void write(ostream &os);

  virtual void read(istream &is);

};

#endif // MULTIMEDIA_H
