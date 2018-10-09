#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
  
private:
  int chapNumber = 0;
  int *chapters = nullptr;

  // void copyChapters(int size, const int *chap);

public:

  Film(const string& name, const string& path, int duration, int size, const int *chapter);

  ~Film();

  void setChapters(const int *chapter, int size);
  
  const int *  getChapters() const;

  const int  getChapNumber();

  void show(ostream &s);

};

#endif // FILM_H