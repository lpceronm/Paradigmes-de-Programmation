#include "Store.h"


Store::Store(){}

Smt Store::createPhoto(const string& storeName,
  const string& name, const string& path, double latitude, double longitude){
  Smt p(new Photo(name,path,latitude,longitude));
  mediaFile[storeName] = p;
  return p;
}

Smt Store::createVideo(const string& storeName,const string& name, 
  const string& path, double duration){
  Smt v(new Video(name,path,duration));
  mediaFile[storeName] = v;
  return v; 
}

Smt Store::createFilm(const string& storeName,const string& name, 
  const string& path, int duration, int size, const int *chapter){
  Smt f(new Film(name,path,duration,size,chapter));
  mediaFile[storeName] = f;
  return f; 
}

Sgr Store::createGroup(const string& storeName, const string& name){
  Sgr gr(new Group(name));
  groupFolder[storeName] = gr;
  return gr;

}