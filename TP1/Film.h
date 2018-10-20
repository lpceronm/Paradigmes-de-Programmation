#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
  
private:
  int chapNumber = 0;
  int *chapters =  new int[0];

  void copyChapters(int size, const int *chap);

public:

  Film();

  Film(const string& name, const string& path, int duration, int size, const int *chapter);

  Film( const Film& );

  Film& operator=(const Film&);

  ~Film();

  void setChapters(const int *chapter, int size);
  
  const int *  getChapters() const;

  const int  getChapNumber();

  const char* className() const { return "Film"; }

  void show(ostream &s);

  void write(ostream &os);

  void read(istream &is);

};

#endif // FILM_H