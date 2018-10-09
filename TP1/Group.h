#ifndef GROUP_H
#define GROUP_H
#include <list>
#include "Multimedia.h"
#include <memory>

using Smt = std::shared_ptr<Multimedia>;

class Group : public list<Smt>{

private:
  string name = "";

public:
  Group(const string& name) : name(name) {}

  string getName()const{ return name; }
  void setName( const string& set_name) {name = set_name; }

  void show(ostream &s){
    s << "Group name: " + name + "\n";
    for (iterator it = begin(); it != end(); ++it)
      (*it)->show(s);
    s << endl;
  }
};

#endif // GROUP_H