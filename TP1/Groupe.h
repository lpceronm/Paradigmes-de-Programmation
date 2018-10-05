#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include "Multimedia.h"


class Groupe : public list<Multimedia *>{

private:
  string name = "";

public:
  Groupe(string name): name(name) { }

  string getName(){
    return name;
  }

  void show(ostream& s){
    for (iterator it= begin(); it != end(); ++it)
     (*it)->show(s);
  }
};

#endif // GROUPE_H