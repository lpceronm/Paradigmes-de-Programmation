/*!
 * \file
 * \brief  Store class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
#include "Store.h"
#include "Exception.h"

/** 
 * @brief Construct a new Store:: Store object
 * The Store constructor initializes the request maps which has the possible requests from a client.
 */
Store::Store(){
  requests["SEARCH"] = &Store::showElement;
  requests["PLAY"] = &Store::playElement;
  requests["ALL"] = &Store::showAll;
  requests["DELMEDIA"] = &Store::deleteElement;
  requests["DELGROUP"] = &Store::deleteGroup;
}

/**
 * @brief Destroy the Store object
 * 
 */
Store::~Store(){
  cout << "Deleted Store \n";
}

/**
 * @brief  createPhoto returns a smart pointer of type Smt
 * 
 * @param name 
 * @param path 
 * @param latitude 
 * @param longitude 
 * @return Smt 
 */
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

/**
 * @brief 
 * 
 * @param name 
 * @return Smt 
 */
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

/**
 * @brief createVideo returns a smart pointer of type Smt, recieves all the attributes to create a Video
 * 
 * @param name 
 * @param path 
 * @param duration 
 * @return Smt 
 */
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
/**
 * @brief  createVideo returns a smart pointer of type Smt, recieves all the attributes to create a Video 
 * 
 * @param name 
 * @return Smt 
 */
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

/**
 * @brief createFilm returns a smart pointer of type Smt, recieves all the attributes to create a Film 
 * 
 * @param name 
 * @param path 
 * @param duration 
 * @param size 
 * @param chapter 
 * @return Smt 
 */
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

/**
 * @brief  createFilm returns a smart pointer of type Smt, recieves the name to create a Film 
 * 
 * @param name 
 * @return Smt 
 */
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

/**
 * @brief createGroup returns a smart pointer of type Sgr, recieves all the attributes to create a Group
 * 
 * @param name 
 * @return Sgr 
 */

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

/**
 * @brief showAll shows all the elements in the database
 * 
 * @param name 
 * @param s 
 */

void Store::showAll(const string &name, ostream &s){
  for (auto it = mediaFolder.begin(); it != mediaFolder.end(); it++)
    it->second->show(s);
  for (auto it = groupFolder.begin(); it != groupFolder.end(); it++)
    it->second->show(s);
}

/**
 * @brief showElement given a name shows an specific element in the database.
 * 
 * @param name 
 * @param s 
 */
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

/**
 * @brief playElement given a name plays an specific element in the database.
 * 
 * @param name 
 * @param s 
 */
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

/**
 * @brief deleteElement given a name delets an specific element in the database.
 * 
 * @param name 
 * @param s 
 */

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

//** @brief deleteGroup given a name shows an specific group in the database. */

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

/**
 * @brief createMult is the factory to create an object given a class name.
 * 
 * @param clss 
 * @param is 
 * @return Smt 
 */

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

/**
 * @brief save creates a file with all the elements in the database.
 * 
 * @param outputName 
 * @return true 
 * @return false 
 */

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


/**
 * 
 * \fn load
 * @brief populates the database from a textfile.
 * 
 * @param inputName 
 * @return true 
 * @return false 
 */
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

/**
 * \fn  processRequest
 * @brief processRequest manages the server connection, it creates a thread for each client 
 * 
 * @param cnx 
 * @param request 
 * @param response 
 * @return true 
 * @return false 
 */
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
