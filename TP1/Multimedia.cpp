#include "multimedia.h"

void Multimedia::show(ostream & s){
  s <<"Name: " + getName()<< '\n'<<"Path: " + getPath() << '\n';
}
