#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia{
  
private:
  int duration = 0;

public:
  Video();
  
  Video(const string& name, const string& path, int duration);

  virtual ~Video();

  virtual void setDuration(int dur);
  
  virtual int getDuration() const;

  virtual void show(ostream &s) ;

  virtual void play() ;

};

#endif // VIDEO_H
