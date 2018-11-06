/*!
 * \file
 * \brief  Video class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
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

  virtual const char* className() const { return "Video"; }

  virtual void show(ostream &s) ;

  virtual void play() ;

  virtual void write(ostream &os);

  virtual void read(istream &is);

};

#endif // VIDEO_H
