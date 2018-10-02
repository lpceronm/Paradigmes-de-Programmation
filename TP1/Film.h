#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
private:
  int * chapters = NULL;

public:

  Film(string name, string path, int duration, int * chapter, int size): Video(name,path,duration), chapters(new int[size]){   
    for(int i = 0; i < size; i++){  
      chapters[i] = chapter[i];
    } 
  }

  
  int * getChapters(){
    return chapters;
  }
};

#endif // FILM_H