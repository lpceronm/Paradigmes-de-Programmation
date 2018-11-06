
/*!
 * \file
 * \brief  Class in charge of the exception handling 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 * This class has the functions to check whether there is an exception of existance or a pattern
 *
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <regex>

/**
 * \struct  ExistenceException
 * @brief raises an error when:
 * - Creating  an object that already exists in the database 
 * - When name is search that doesn't exist 
 */
struct ExistenceException : public exception{
  string exc;
  ExistenceException(string e) : exc(e) {}
};

/**
 * \fn existsElement
 * @brief existsElement given a name check whether it exists
 * 
 * @param file 
 * @param name 
 * @return true 
 * @return false 
 */
bool existsElement(File file, const string &name){
  
  if (file.find(name) != file.end())
    throw ExistenceException(name);
  else
    return false;
}

/**
 * \fn existsGroup
 * @brief existsGroup given a name check whether it exists
 * 
 * @param file 
 * @param name 
 * @return true 
 * @return false 
 */
bool existsGroup(Folder file, const string &name){
  if (file.find(name) != file.end())
    throw ExistenceException(name);
  else
    return false;
}

/**
 * \fn notFoundElement 
 * @brief notFoundElement raises when an element is not found
 * 
 * @param file 
 * @param name 
 * @return true 
 * @return false 
 */
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

/**
 * @brief The PatternException raises an error when a file name doesn't match a permited pattern.
 */
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