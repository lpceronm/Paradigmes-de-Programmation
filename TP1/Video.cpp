#include "Video.h"

void Video::show(ostream & s){
  Multimedia::show(s);
  s << getDuration() <<'\n';
}