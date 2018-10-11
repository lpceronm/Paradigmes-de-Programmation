#include "Store.h"


Store::Store(){}
Store::~Store(){ 
  cout<< "Deleted Store \n";
}

Smt Store::createPhoto( const string& name, const string& path, 
double latitude, double longitude){
  Smt p(new Photo(name,path,latitude,longitude));
  mediaFolder[name] = p;
  return p;
}

Smt Store::createVideo(const string& name, const string& path, double duration){
  Smt v(new Video(name,path,duration));
  mediaFolder[name] = v;
  return v; 
}

Smt Store::createFilm(const string& name, const string& path,
 int duration, int size, const int *chapter){
  Smt f(new Film(name,path,duration,size,chapter));
  mediaFolder[name] = f;
  return f; 
}

Sgr Store::createGroup( const string& name){
  Sgr gr(new Group(name));
  groupFolder[name] = gr;
  return gr;
}

void Store::showElement(const string& name, ostream& s ){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end()){
      mult->second->show(s);
  }else{
    auto group = groupFolder.find(name);
    
    if (group != groupFolder.end()) {
      group->second->show(s);
    }else{
      s << "Multimedia element or group not found" << endl;
    }
  }
}

void Store::playElement(const string& name){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end()){
      mult->second->play();
  }else{
      cout << "Multimedia element not found" << endl;
  }
}

void Store::deleteElement(const string& name){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end()){
      mediaFolder.erase(mult);
  }else{
      cout << "Multimedia element not found" << endl;
  }

}
void Store::deleteGroup(const string& name){
  auto group = groupFolder.find(name); 
  if (group != groupFolder.end()) {
    groupFolder.erase(group);
  }else{
    cout << "Group not found" << endl;
  }
}