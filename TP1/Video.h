#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia
{
private:
  int duration = 0;

public:
  Video(string name, string path, int duration) : duration(duration), Multimedia(name, path) {}
  void setDuration(int duration) { duration = duration; }
  int getDuration() const { return duration; }
  void show(ostream &);
  ~Video();
};

#endif // VIDEO_H
