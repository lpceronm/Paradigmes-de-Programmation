#include "Video.h"
#include "Multimedia.h"


void Video::show(ostream &s){
   Multimedia::show(s);
    s << "Duration: " << getDuration() << '\n';
}

void Video::play(){
   string command("open " + getPath() + " &");
    system(command.c_str());
}