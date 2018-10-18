#include "Video.h"
#include "Multimedia.h"

Video::Video(){};

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

void Video::write(ostream &os){
  os << className()<< '\n';
  Multimedia::write(os);
  os<< duration << '\n';
}

void Video::read(istream &is){  
  Multimedia::read(is);
  string dur ;
  getline(is,dur);
  duration = atoi(dur.c_str());
}
