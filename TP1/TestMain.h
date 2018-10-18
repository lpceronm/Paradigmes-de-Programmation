#ifndef TEST_M
#define TEST_M

#include <iostream>
#include <fstream>
#include <memory>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Store.h"
#include "Factory.h"

using namespace std;
using Sst = std::shared_ptr<Store>;

void testMain(){
  int *chap2 = new int[3]{1, 2, 3};
  int *chap = new int[12]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  // Film *f3 = new Film("film", "path", 20, 12, chap3);
  // Film * f1 = new Film("film", "path", 20, 3, chap2);
  // f1->show(cout);

  // *f1 = *f;
  // delete f;
  // f1->show(cout);

  // f->show(cout);
  // cout<< "Holaaaa";
  // f1->show(cout);
  // delete f;

  // f1->show(cout);

  Sst store(new Store());
  Smt p = store->createPhoto("PhotoMap", "photo/test.png", 1, 1 + 2.0);
  Smt p1 = store->createPhoto("Photo", "photo/test.png", 1.02, 3.1+ 2.0);
  Smt v1 = store->createVideo("Video2", "video/test.png", 11);
  Smt f = store->createFilm("film", "path", 20, 12, chap);
  Smt f2 = store->createFilm("film2", "pa2th", 20, 3, chap2);

  p.reset();
  p1.reset();
  v1.reset();
  f.reset();
  f2.reset();

  // store->showElement("PhotoMap", cout);
  // Group *list = new Group("name");
  // Group other_list("other list");

  // Smt p1(new Photo("Photo", "photo/test.png", 1.02, 3.1+ 2.0));
  // Smt p2(new Photo("Photo2", "photo/test.png", 1.0, 4.1 + 2.0));
  // Smt p3(new Photo("Photo3", "photo/test.png", 1.0, 1.3 + 2.0));
  // Smt v1(new Video("vidi", "video/test.png", 11));
  // Smt v2(new Video("Video2", "video/test.png", 11));
  // Smt f(new Film("film", "path", 20, 12, chap));
  // Smt f2(new Film("film2", "pa2th", 20, 3, chap2));


  // ofstream myfile;
  // myfile.open ("example.txt");

  
  // f->write(myfile);
  // f2->write(myfile);
  // myfile.close();

  bool i = store->save("example.txt");

  Sst store1(new Store());

  ifstream infile("example.txt");
  
  if (infile) {
    while(infile){
      string clss;
      getline(infile,clss);
      Smt inv = store1->createMult(clss,infile);
      if (inv) inv->read(infile);
    }
    infile.close();
  }
   
   store1->showElement("film",cout);
   store1->showElement("film2",cout);
  
  

 

  // Sgr gr = store->createGroup("groupname");
  // gr->push_back(p1);
  // gr->push_back(p);
  // p.reset();

  // gr->show(cout);
  // gr.reset();

  // store->showElement("Name", cout);
  // store->showElement("groupname", cout);
  // store->showElement("PhotoMap", cout);
  // // store->playElement("PhotoMap");
  // // store->playElement("Name");
  // store->deleteElement("PhotoMap");
  // store->deleteGroup("groupname");

  // // delete[] chap;

  // cout << "**************** Something different" << endl;
  // list->push_back(p1);
  // list->push_back(v1);
  // list->push_back(f);
  // list->push_back(p3);
  // other_list.push_back(p1);
  // other_list.push_back(p2);
  // other_list.push_back(f);
  // other_list.push_back(v2);

  // list->show(cout);
  // other_list.show(cout);

  // cout << "****** DELETED Map group \n";

  // store->deleteGroup("groupname");

  // for (auto &it : *list)
  //   it->show(cout);
  // cout << endl;

  // delete list;
  // cout << "****** DELETED LIST \n";
  // p3.reset();

  // for (auto &it : other_list)
  //   it->show(cout);
  // cout << endl;

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
}
#endif