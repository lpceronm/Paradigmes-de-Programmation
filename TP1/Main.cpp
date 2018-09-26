//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
using namespace std;

int main(int argc, const char *argv[]){

  Multimedia *m = new Multimedia("nombre", "path");
  m->show(cout);
  return 0;
}
