#include "Video.h"
#include "Multimedia.h"

Video::~Video() { cout<< "Videos deleted "+ getName() + "\n";}

void Video::show(ostream &s){
   Multimedia::show(s);
    s << "Duration: " << getDuration() << '\n';
}

void Video::play(){
   string command("open " + getPath() + " &");
    system(command.c_str());
}