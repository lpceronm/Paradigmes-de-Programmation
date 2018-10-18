#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia{

private:

  double latitude = 0.0;
  double longitude = 0.0;

public:
  Photo();

  Photo(const string& name, const string& path, double latitude, double longitude); 

  ~Photo();

  void setlatitude(double lat);
  
  double getlatitude() const;

  void setlongitude(double lng);
  
  double getlongitude() const;

  void show(ostream &s);

  void play();
  
};

#endif // PHOTO_H
