/*!
 * \file
 * \brief  Film class 
 * \author Laura CERON
 * \date   6 nov. 2018
 *  
 */

#include "Film.h"
#include "Video.h"

/**
 * @brief Construct a new Film object
 * 
 */
Film::Film(){}

Film::Film(const string &name, const string &path, int duration, int size, const int *chapter) : 
  Video(name, path, duration), chapNumber(size), chapters(new int[size]){
  copyChapters(size, chapter);
  // memcpy(chapters, chapter, size * (sizeof(chapter)));
}

/**
 * @brief Copy constructor
 * 
 * @param from 
 */
Film::Film(const Film& from): Video(from){ 
  chapNumber = from.chapNumber;
  chapters = new int[from.chapNumber];
  if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
}

Film& Film:: operator=(const Film& from) {
  Video::operator=(from);
  chapNumber = from.chapNumber;
  if (from.chapters && chapters) {
    chapters = new int[from.chapNumber];
    copyChapters(from.chapNumber, from.chapters);
  }else{
    delete[] chapters;
    chapters = new int[from.chapNumber];
    if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
  }
  return *this;
}
/**
 * @brief Destroy the Film:: Film object
 * 
 */
Film::~Film(){
  delete[] chapters;
  cout << "Films deleted " + getName() + "\n";
}

void Film::setChapters(const int *chapter, int size){
  chapNumber = size;
  chapters = new int[size];
  copyChapters(size, chapter);
  // memcpy(chapters, chapter, size * (sizeof(chapter)));
}
/**
 * @brief getters
 * 
 * @return const int* 
 */
const int *Film::getChapters() const { return chapters; }

const int Film::getChapNumber() { return chapNumber; }

void Film::show(ostream &s){
  Video::show(s);
  for (int i = 0; i < chapNumber; i++){
    s << ";\t Chapter" << i << ": " << chapters[i] << ",  ";
  }
}

/**
 * @brief write, serializer
 * 
 * @param os 
 */

void Film::write(ostream &os){
  os << className()<< '\n';
  Multimedia::write(os);
  os << getDuration() << '\n';
  os << getChapNumber() << '\n';
  
  for(int i = 0; i < chapNumber; i++)
    os << '\t' << chapters[i] << '\n'; 
}

/**
 * @brief read, serializer
 * 
 * @param is 
 */

void Film::read(istream &is){
  Video::read(is);
  string num ;
  getline(is,num);
  chapNumber = atoi(num.c_str());
  chapters = new int[chapNumber];
  for(int i = 0; i < chapNumber; i++){
    string chDur;
    getline(is,chDur);
    chapters[i]= atoi(chDur.c_str());
  }
}

/**
 * @brief makes the deep copy of the chapters array
 * 
 * @param size 
 * @param chap 
 */
void Film::copyChapters(int size, const int *chap){
  for (int i = 0; i < size; i++){
    chapters[i] = chap[i];
  }
}