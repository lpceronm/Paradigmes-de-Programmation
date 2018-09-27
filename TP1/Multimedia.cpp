#include "Multimedia.h"

void Multimedia::show(ostream & s){
  s <<"Name: " + getName()<< '\n'<<"Path: " + getPath() << '\n';
}
