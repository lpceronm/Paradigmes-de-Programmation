#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia{
  
private:
  int duration = 0;

public:
  Video(const string& name, const string& path, int duration) : Multimedia(name, path), duration(duration) {}

  virtual ~Video() { cout<< "Videos deleted "+ getName() + "\n";}

  virtual void setDuration(int dur) { duration = dur; }
  
  virtual int getDuration() const { return duration; }

  virtual void show(ostream &s) ;

  virtual void play() ;

};

#endif // VIDEO_H
