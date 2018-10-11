#include "Store.h"


Store::Store(){}

Smt Store::createPhoto(const string& storeName,
  const string& name, const string& path, double latitude, double longitude){
  Smt p(new Photo(name,path,latitude,longitude));
  mediaFile[storeName] = p;
  return p;
}