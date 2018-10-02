#ifndef GROUPE_H
#define GROUPE_H
#include <list>
#include "Multimedia.h"


class Groupe : public list<Multimedia *>{

private:
  string name = "";

public:
  Groupe(string name): name(name) { }

};

#endif // GROUPE_H