#include "Store.h"
#include <fstream> // std::filebuf

Store::Store() {
  requests["SEARCH"] = &Store::showElement;
  requests["PLAY"] = &Store::playElement;
}

Store::~Store(){
  cout << "Deleted Store \n";
}

Smt Store::createPhoto(const string &name, const string &path,
  double latitude, double longitude){
  mediaFolder[name] = Smt(new Photo(name, path, latitude, longitude));
  return mediaFolder[name];
}

Smt Store::createPhoto(const string &name){
  mediaFolder[name] = Smt(new Photo());
  mediaFolder[name]->setName(name);
  return mediaFolder[name];
}

Smt Store::createVideo(const string &name, const string &path, double duration){
  mediaFolder[name] = Smt(new Video(name, path, duration));
  ;
  return mediaFolder[name];
}

Smt Store::createVideo(const string &name){
  mediaFolder[name] = Smt(new Video());
  mediaFolder[name]->setName(name);
  return mediaFolder[name];
}

Smt Store::createFilm(const string &name, const string &path,
  int duration, int size, const int *chapter){
  mediaFolder[name] = Smt(new Film(name, path, duration, size, chapter));
  ;
  return mediaFolder[name];
}

Smt Store::createFilm(const string &name){
  mediaFolder[name] = Smt(new Film());
  mediaFolder[name]->setName(name);
  return mediaFolder[name];
}

Sgr Store::createGroup(const string &name){
  groupFolder[name] = Sgr(new Group(name));
  return groupFolder[name];
}

void Store::showElement(const string &name, ostream &s){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end())
    mult->second->show(s);
  else{
    auto group = groupFolder.find(name);
    if (group != groupFolder.end())
      group->second->show(s);
    else
      s << "Multimedia element or group not found" << endl;
  }
}

void Store::playElement(const string &name, ostream& s){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end()){
    s << "Playing: "<< name<< endl;
    mult->second->play();
  } else
    s << "Multimedia element not found" << endl;
}

void Store::deleteElement(const string &name){
  auto mult = mediaFolder.find(name);
  if (mult != mediaFolder.end()){
    mult->second.reset();
    mediaFolder.erase(mult);
  }else{
    cout << "Multimedia element not found" << endl;
  }
}

void Store::deleteGroup(const string &name){
  auto group = groupFolder.find(name);
  if (group != groupFolder.end()){
    group->second.reset();
    groupFolder.erase(group);
  }
  else{
    cout << "Group not found" << endl;
  }
}

Smt Store::createMult(const string& clss, istream &is){
  string name;
    if (clss.compare("Photo") == 0){
      getline(is,name);
      return createPhoto(name);
    }else if (clss.compare("Video") == 0){
      getline(is,name);
      return createVideo(name);
    }else if (clss.compare("Film") == 0){
      getline(is,name);
      return createFilm(name);
    }else 
      return nullptr;
}

bool Store::save(const string &outputName){
  ofstream outF(outputName); 
  if (!outF){
    cerr << "Can't open file \n";
    return false;
  }else{
    for(auto it = mediaFolder.begin(); it!= mediaFolder.end();it++)
      it->second->write(outF);
    outF.close();  
    return true;  
  }
}

bool Store::load(const string &inputName){ 
  ifstream inF(inputName);
  if (!inF){
    cerr << "Can't open file \n";
    return false;
  }else{
    while(inF){
      string clss;
      getline(inF,clss);
      Smt inv = createMult(clss,inF);
      if (inv) inv->read(inF);
    }
    inF.close();
    return true; 
  }  
}

bool Store::processRequest(TCPConnection& cnx, const string& request, string& response){
  
  cerr << "\nRequest: '" << request << "'" << endl;
  response = "";
  // Request format <METHOD>?<name>

  istringstream inReq(request);
  ostringstream resp;

  string command, parameter, parnm;
  getline(inReq, command, '?');
  getline(inReq, parameter);

  if(requests.find(command) != requests.end())
    (this->*requests[command])(parameter,resp);
  else
    resp << "Not command found";

  if (response == "") 
    response =  resp.str();

  cerr << "response: " << response << endl;
  

  return true;

}
