#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
private:
  int * chapters = NULL;

public:
  Film();
};

#endif // FILM_H