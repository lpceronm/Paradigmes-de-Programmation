#include "Film.h"
#include "Video.h"


void Film::show(ostream &s){
   Video::show(s);
    s << "Chapters duration: " << "\n";
    for(int i = 0; i < chapNumber; i++){
      s <<"\t Chapter" << i << ": " << chapters[i] << "\n";
    }
}