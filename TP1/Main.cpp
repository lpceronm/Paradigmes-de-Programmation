#include <iostream>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"


using namespace std;

int main(int argc, const char *argv[]){

  Multimedia ** media = new  Multimedia * [10];

  // Video * v = new Video("video1","video.mp4",30);
  // v->show(cout);
  // v->play();
  
  double d = 0.0;
  for( int i = 0; i < 10; i++){
    if (i % 2 == 0) {
      media[i] = new Video("video" + to_string(i), "video/video.mp4",i);
    }
    else {
      d+= 1.1;
      media[i] = new Photo("Photo" + to_string(i), "photo/test.png",d,d+2.0);
    }
  }
  
  
  for(int  i = 0; i < 10 ; i++){
    Multimedia * m = media[i];
    m->show(cout);
    m->play();
    cout << endl ;
  }
  
  // Photo * p = new Photo("photo1","/rutaphoto",10.1, 22.0);
  // p->show(cout);
  return 0;
}
