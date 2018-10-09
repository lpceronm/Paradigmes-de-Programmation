#include "Photo.h"
#include "Multimedia.h"


Photo::~Photo(){ cout<< "Photos deleted "+ getName() + "\n";}

void Photo::show(ostream &s){
   Multimedia::show(s);
    s << "Latitude: " << getlatitude() << '\n';
    s << "Longitude: " << getlongitude() << '\n';
}

void Photo::play(){
   string command("open " + getPath() + " &");
    system(command.c_str());
}