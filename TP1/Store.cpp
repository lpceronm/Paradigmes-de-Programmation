#include "Store.h"
#include "Exception.h"

Store::Store(){

  //  Server requests
  requests["SEARCH"] = &Store::showElement;
  requests["PLAY"] = &Store::playElement;
  requests["ALL"] = &Store::showAll;
  requests["DELMEDIA"] = &Store::deleteElement;
  requests["DELGROUP"] = &Store::deleteGroup;
}

Store::~Store(){
  cout << "Deleted Store \n";
}

Smt Store::createPhoto(const string &name, const string &path,
  double latitude, double longitude){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Photo(name, path, latitude, longitude));
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The photo: " << e.exc << " already exists" << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Smt Store::createPhoto(const string &name){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Photo());
    mediaFolder[name]->setName(name);
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The photo: " << e.exc << " already exists" << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Smt Store::createVideo(const string &name, const string &path, double duration){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Video(name, path, duration));
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The video: " << e.exc << " already exists" << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Smt Store::createVideo(const string &name){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Video());
    mediaFolder[name]->setName(name);
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The video: " << e.exc << " already exists" << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Smt Store::createFilm(const string &name, const string &path,
  int duration, int size, const int *chapter){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Film(name, path, duration, size, chapter));
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The film: " << e.exc << " already exists.  " << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Smt Store::createFilm(const string &name){
  try{
    matchPattern(name);
    existsElement(mediaFolder, name);
    mediaFolder[name] = Smt(new Film());
    mediaFolder[name]->setName(name);
    return mediaFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The film: " << e.exc << " already exists.  " << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

Sgr Store::createGroup(const string &name){
  try{
    matchPattern(name);
    existsGroup(groupFolder, name);
    groupFolder[name] = Sgr(new Group(name));
    return groupFolder[name];
  }catch (ExistenceException &e){
    std::cerr << "The group: " << e.exc << " already exists.  " << '\n';
    return nullptr;
  }catch (PatternException & e){
    std::cerr << e.exc << ": doesn't have a permitted pattern" << '\n';
    return nullptr;
  }
}

void Store::showAll(const string &name, ostream &s){
  for (auto it = mediaFolder.begin(); it != mediaFolder.end(); it++)
    it->second->show(s);
  for (auto it = groupFolder.begin(); it != groupFolder.end(); it++)
    it->second->show(s);
}

void Store::showElement(const string &name, ostream &s){
  try{
    matchPattern(name);
    notFoundElement(mediaFolder, name);
    auto mult = mediaFolder.find(name);
    mult->second->show(s);
  }catch (ExistenceException &e){
    std::cerr << "A multimedia element named: " << e.exc << " doesn't exists. ";
    try{
      notFoundGroup(groupFolder, name);
      auto group = groupFolder.find(name);
      group->second->show(s);
    }catch (ExistenceException &e){
      s << "Multimedia element or group " << e.exc << " not found.  ";
    }
  }catch (PatternException & e){
    s << e.exc << ": doesn't have a permitted pattern.  " ;
  }
}

void Store::playElement(const string &name, ostream &s){
  try{
    matchPattern(name);
    notFoundElement(mediaFolder, name);
    auto mult = mediaFolder.find(name);
    s << "Playing: " << name << "  ";
    mult->second->play();
  }catch (ExistenceException &e){
    s << "Multimedia element " << e.exc << " not found.  ";
  }catch (PatternException & e){
    s << e.exc << ": doesn't have a permitted pattern.  " ;
  }
}

void Store::deleteElement(const string &name, ostream &s){
  try{
    matchPattern(name);
    notFoundElement(mediaFolder, name);
    auto mult = mediaFolder.find(name);
    mult->second.reset();
    mediaFolder.erase(mult);
    s << "Deleted: " << name;
  }catch (ExistenceException &e){
    s << "Multimedia element " << e.exc << " not found.  ";
  }catch (PatternException & e){
    s << e.exc << ": doesn't have a permitted pattern.  " ;
  }
}

void Store::deleteGroup(const string &name, ostream &s){
  try{
    matchPattern(name);
    notFoundGroup(groupFolder, name);
    auto group = groupFolder.find(name);
    group->second.reset();
    groupFolder.erase(group);
    s << "Deleted: " << name;
  }catch (ExistenceException &e){
    s << "Group:  " << e.exc << " not found.  ";
  }catch (PatternException & e){
    s << e.exc << ": doesn't have a permitted pattern.  " ;
  }
}

//  Factory to create objects
Smt Store::createMult(const string &clss, istream &is){
  string name;
  if (clss.compare("Photo") == 0){
    getline(is, name);
    return createPhoto(name);
  }
  else if (clss.compare("Video") == 0){
    getline(is, name);
    return createVideo(name);
  }else if (clss.compare("Film") == 0){
    getline(is, name);
    return createFilm(name);
  }else
    return nullptr;
}

// Serialization

bool Store::save(const string &outputName){
  ofstream outF(outputName);
  if (!outF){
    cerr << "Can't open file \n";
    return false;
  }else{
    for (auto it = mediaFolder.begin(); it != mediaFolder.end(); it++)
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
    while (inF){
      string clss;
      getline(inF, clss);
      Smt inv = createMult(clss, inF);
      if (inv)
        inv->read(inF);
    }
    inF.close();
    return true;
  }
}

// Process clients requests

bool Store::processRequest(TCPConnection &cnx, const string &request, string &response){

  cerr << "\nRequest: '" << request << "'" << endl;
  response = "";
  // Request format <METHOD>?<name>

  istringstream inReq(request);
  ostringstream resp;

  string command, parameter = "";
  getline(inReq, command, '?');
  getline(inReq, parameter);

  TCPLock lock(cnx);

  if (requests.find(command) != requests.end())
    (this->*requests[command])(parameter, resp);
  else if (command == "QUIT"){
    resp << "Connexion closed";
    return false;
  }else
    resp << "Not command found";

  if (response == "")
    response = resp.str();

  cerr << "response: " << response << endl;

  return true;
}
