#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
  
private:
  int chapNumber = 0;
  int *chapters = NULL;

  void copyChapters(int size, int *chap){
    for (int i = 0; i < size; i++){
      chapters[i] = chap[i];
    }
  }

public:

  Film(const string& name, const string& path, int duration, int size, int *chapter) :
    Video(name, path, duration), chapNumber(size),chapters(new int[size]){
      copyChapters(size, chapter);
  }

  ~Film();

  const int *  getChapters() const{ return chapters;}

  void setChapters(int *chapter, int size){
    chapNumber = size;
    chapters = new int[size];
    copyChapters(size, chapter);
  }

  void show(ostream &s);

};

#endif // FILM_H