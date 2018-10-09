#include "Video.h"
#include "Multimedia.h"

Video::Video(const string& name, const string& path, int duration) :
  Multimedia(name, path), duration(duration){}

Video::~Video() { cout<< "Videos deleted "+ getName() + "\n";}

void Video::setDuration(int dur) { duration = dur; }

int Video:: getDuration() const { return duration; }


void Video::show(ostream &s){
   Multimedia::show(s);
    s << "Duration: " << getDuration() << '\n';
}

void Video::play(){
   string command("open " + getPath() + " &");
    system(command.c_str());
}