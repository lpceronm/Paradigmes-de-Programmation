//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Video.h"

using namespace std;

int main(int argc, const char *argv[]){

  Video * v = new Video("video1","/ruta",30);
  v->show(cout);
  return 0;
}
