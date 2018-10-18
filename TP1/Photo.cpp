#include "Photo.h"
#include "Multimedia.h"

Photo::Photo(){};

Photo::Photo(const string &name, const string &path, double latitude, double longitude) : Multimedia(name, path), latitude(latitude), longitude(longitude) {}

Photo::~Photo() { cout << "Photos deleted " + getName() + "\n"; }

void Photo::setlatitude(double lat) { latitude = lat; }

double Photo::getlatitude() const { return latitude; }

void Photo::setlongitude(double lng) { longitude = lng; }

double Photo::getlongitude() const { return longitude; }

void Photo::show(ostream &s){
  Multimedia::show(s);
  s << "Latitude: " << getlatitude() << '\n';
  s << "Longitude: " << getlongitude() << '\n';
}

void Photo::play(){
  string command("open " + getPath() + " &");
  system(command.c_str());
}

void Photo::write(ostream &os){
  os << className()<< '\n';
  Multimedia::write(os);
  os << latitude << '\n' << longitude << '\n';
}

void Photo::read(istream &is){
   Multimedia::read(is);
   string lat;
   string lng;
   getline(is,lat);
   getline(is,lng);
   latitude = atof(lat.c_str());
   longitude = atof(lng.c_str());
}