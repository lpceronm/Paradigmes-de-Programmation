#include "Multimedia.h"
#include "Group.h"

Group::Group(const string& name) : name(name) {}

string Group::getName()const{ return name; }

void Group::setName( const string& set_name) {name = set_name; }

void Group::show(ostream &s){
    s << "Group name: " + name + "\n";
    for (iterator it = begin(); it != end(); ++it)
      (*it)->show(s);
    s << endl;
  }