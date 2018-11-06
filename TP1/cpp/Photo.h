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

  const char* className() const { return "Photo"; }

  void show(ostream &s);

  void play();

  void write(ostream &os);

  void read(istream &is);
  
};

#endif // PHOTO_H
