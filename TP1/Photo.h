#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia{

private:

  double latitude = 0.0;
  double longitude = 0.0;

public:

  Photo(const string& name, const string& path, double latitude, double longitude) : 
    Multimedia(name, path), latitude(latitude),longitude(longitude) {}

  ~Photo(){ cout<< "Photos deleted "+ getName() + "\n";}

  void setlatitude(double lat) { latitude = lat; }
  
  double getlatitude() const { return latitude; }

  void setlongitude(double lng) { longitude = lng; }
  
  double getlongitude() const { return longitude; }

  void show(ostream &s);

  void play();
  
};

#endif // PHOTO_H
