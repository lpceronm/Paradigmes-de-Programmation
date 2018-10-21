#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <regex>

struct ExistenceException : public exception{
  string exc;
  ExistenceException(string e) : exc(e) {}
};

bool existsElement(File file, const string &name){
  
  if (file.find(name) != file.end())
    throw ExistenceException(name);
  else
    return false;
}

bool existsGroup(Folder file, const string &name){
  if (file.find(name) != file.end())
    throw ExistenceException(name);
  else
    return false;
}

bool notFoundElement(File file, const string &name){
  if (file.find(name) == file.end())
    throw ExistenceException(name);
  else
    return false;
}

bool notFoundGroup(Folder file, const string &name){
  if (file.find(name) == file.end())
    throw ExistenceException(name);
  else
    return false;
}

struct PatternException : public exception{
  string exc;
  PatternException(string e) : exc(e){ };
};

bool matchPattern(const string& name){
  regex rgx("[[:alnum:]]+");
  if (!regex_match(name,rgx)) 
    throw PatternException(name);
  else 
    return true;  
}

#endif // EXCEPTION_H