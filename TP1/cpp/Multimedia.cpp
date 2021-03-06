/*!
 * \file
 * \brief  Multimedia class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

Multimedia::Multimedia(){};

Multimedia::Multimedia(const string &name, const string &path) : name(name), path(path) {}

void Multimedia::setName(const string &set_nam) { name = set_nam; }

void Multimedia::setPath(const string &set_path) { path = set_path; }

string Multimedia::getName() const { return name; }

string Multimedia::getPath() const { return path; }

void Multimedia::show(ostream &s){
  s << ";Name: " + getName() << "    "
    << ";Path: " + getPath() << "   ";
}

void Multimedia::write(ostream &s){
  s << getName() << '\n'
    << getPath() << '\n';
}

void Multimedia::read(istream &is){
    getline(is, path);
}
