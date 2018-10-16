#ifndef SERVER_M
#define SERVER_M

#include <iostream>
#include <memory>

#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Store.h"

using namespace std;
using Sst = std::shared_ptr<Store>;

void serverMain(){
  cout << "Funciona con el def"<< endl;
  int *chap = new int[12]{1, 2, 3, 4,5,6,7,8,9,10,11,12};
  int *chap2 = new int[3]{1, 2, 3};
  Film * f = new Film("film", "path", 20, 12, chap);

  Film * f1 = new Film("film", "path", 20, 3, chap2);
  f1->show(cout);

  *f1 = *f;
  delete f;
  f1->show(cout);

}
#endif