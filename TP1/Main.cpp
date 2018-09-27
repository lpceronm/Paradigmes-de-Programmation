#include <iostream>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"


using namespace std;

int main(int argc, const char *argv[]){

  Multimedia ** m = new  Multimedia * [10];

  Video * v = new Video("video1","video.mp4",30);
  v->show(cout);
  v->play();

  // Photo * p = new Photo("photo1","/rutaphoto",10.1, 22.0);
  // p->show(cout);
  return 0;
}
