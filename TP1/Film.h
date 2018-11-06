/*!
 * \file
 * \brief  Film class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */

#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video{
/**
 * @brief Film class 
 * It is a subclass of VIdeo.
 */
private:
  int chapNumber = 0;
  int *chapters =  new int[0];

  /**
   * \fn copyChapters
   * @brief This function makes the deep-copy of the chapters array
   * 
   * @param size 
   * @param chap 
   */
  void copyChapters(int size, const int *chap);

public:

  Film();
  /**
   * @brief Construct a new Film object 
   * 
   * @param name 
   * @param path 
   * @param duration 
   * @param size 
   * @param chapter 
   */
  Film(const string&name, const string& path, int duration, int size, const int *chapter);

  /**
   * @brief Copy constructor of the Film object. 
   * 
   */
  Film( const Film& );

  Film& operator=(const Film&);

  ~Film();

  void setChapters(const int *chapter, int size);
  
  const int *  getChapters() const;

  const int  getChapNumber();

  const char* className() const { return "Film"; }

  void show(ostream &s);

  void write(ostream &os);

  void read(istream &is);

};

#endif // FILM_H