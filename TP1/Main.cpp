#include <iostream>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Groupe.h"


using namespace std;

int main(int argc, const char *argv[]){

  Groupe list("name");
  list.push_back(new Photo("Photo", "photo/test.png",1,1+2.0));
  for (auto & it : list) it->show(cout);

  // int chap[] = {1,2,3,4};
  // Film * v = new Film("film","path",20,4,chap);
  // const int * c = v->getChapters();
  // v->show(cout);
  
  
  // Multimedia ** media = new  Multimedia * [10];
  
  // double d = 0.0;
  // for( int i = 0; i < 10; i++){
  //   if (i % 2 == 0) {
  //     media[i] = new Video("video" + to_string(i), "video/video.mp4",i);
  //   }
  //   else {
  //     d+= 1.1;
  //     media[i] = new Photo("Photo" + to_string(i), "photo/test.png",d,d+2.0);
  //   }
  // }
  
  
  // for(int  i = 0; i < 10 ; i++){
  //   Multimedia * m = media[i];
  //   m->show(cout);
  //   m->play();
  //   cout << endl ;
  // }
  
  


  return 0;
}
