#include <iostream>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"


using namespace std;

int main(int argc, const char *argv[]){

  Video * v = new Video("video1","/ruta",30);
  v->show(cout);

  Photo * p = new Photo("photo1","/rutaphoto",10.1, 22.0);
  p->show(cout);
  return 0;
}
