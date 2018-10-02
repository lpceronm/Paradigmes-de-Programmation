#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia{

private:

  double latitude = 0.0;
  double longitude = 0.0;

public:

  Photo(string name, string path, double latitude, double longitude) : 
    Multimedia(name, path), latitude(latitude),longitude(longitude) {}

  ~Photo() = default;

  void setlatitude(double lat) { latitude = lat; }
  
  double getlatitude() const { return latitude; }

  void setlongitude(double lng) { longitude = lng; }
  
  double getlongitude() const { return longitude; }

  void show(ostream &s){
    Multimedia::show(s);
    s << "Latitude: " << getlatitude() << '\n';
    s << "Longitude: " << getlongitude() << '\n';
  }

  void play(){
    string command("open " + getPath() + " &");
    system(command.c_str());
  }
  
};

#endif // PHOTO_H
