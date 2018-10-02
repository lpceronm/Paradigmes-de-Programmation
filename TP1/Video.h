#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia{
private:
  int duration = 0;

public:
  Video(string name, string path, int duration) : Multimedia(name, path), duration(duration) {}

  // ~Video();

  void setDuration(int dur) { duration = dur; }
  
  int getDuration() const { return duration; }

  void show(ostream &s){
    Multimedia::show(s);
    s << "Duration: " << getDuration() << '\n';
  }

  void play(){
    string command("open " + getPath() + " &");
    system(command.c_str());
  }

};

#endif // VIDEO_H
