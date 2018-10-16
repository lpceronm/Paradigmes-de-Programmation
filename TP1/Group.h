#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <memory>
#include "Multimedia.h"


using Smt = std::shared_ptr<Multimedia>;

class Group : public list<Smt>{

private:
  string name = "";

public:
  Group(const string& name);

  ~Group();

  string getName() const;

  void setName( const string& set_name);

  void show(ostream &s);
};

#endif // GROUP_H