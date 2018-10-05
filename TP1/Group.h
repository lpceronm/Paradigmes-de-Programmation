#ifndef GROUP_H
#define GROUP_H
#include <list>
#include "Multimedia.h"

class Group : public list<Multimedia *>{

private:
  string name = "";

public:
  Group(string name) : name(name) {}

  string getName(){
    return name;
  }

  void show(ostream &s){
    s << "Group name: " + name + "\n";
    for (iterator it = begin(); it != end(); ++it)
      (*it)->show(s);
    s << endl;
  }
};

#endif // GROUP_H