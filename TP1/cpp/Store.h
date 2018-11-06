/*!
 * \file
 * \brief  Store class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
#ifndef STORE_H
#define STORE_H

#include <memory>
#include <map>
#include <sstream>     
#include <fstream>
#include "Multimedia.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"


using Sgr = std::shared_ptr<Group>;

typedef std::map<string, Smt> File; 
typedef std::map<string, Sgr> Folder;
using namespace cppu;



class Store{
typedef void (Store::*fcn_ptr)(const string& name, ostream& s);
typedef std::map<string, fcn_ptr> Request;

private:
  File mediaFolder;
  Folder groupFolder;
  Request requests;

public:
  Store();

  ~Store();
  
  Smt createPhoto(const string& name, 
    const string& path, double latitude, double longitude);

  Smt createPhoto(const string& name);

  Smt createVideo(const string& name, 
    const string& path, double duration);
  
  Smt createVideo(const string& name);

  Smt createFilm(const string& name, 
    const string& path, int duration, int size, const int *chapter);    
  
  Smt createFilm(const string& name);

  Sgr createGroup(const string& name);

  void showAll(const string& name, ostream&s );

  void showElement(const string& name, ostream& s );

  void playElement(const string& name, ostream& s);

  void deleteElement(const string& name, ostream& s);

  void deleteGroup(const string& name, ostream& s);

  Smt createMult(const string& clss, istream& is);

  bool save(const string& outputName );

  bool load(const string& inputName);

  bool processRequest(TCPConnection& cnx, const string& request, string& response);

};

#endif // STORE_H