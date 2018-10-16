#include "Film.h"
#include "Video.h"

Film::Film(const string &name, const string &path, int duration, int size, const int *chapter) : 
  Video(name, path, duration), chapNumber(size), chapters(new int[size]){
  copyChapters(size, chapter);
  // memcpy(chapters, chapter, size * (sizeof(chapter)));
}

Film::Film(const Film& from): Video(from){ 
  chapNumber = from.chapNumber;
  chapters = new int[from.chapNumber];
  if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
}

Film& Film:: operator=(const Film& from) {
  // Video::operator=(from);
  chapNumber = from.chapNumber;
  copyChapters(from.chapNumber, from.chapters);
  // if (from.chapters && chapters) {
  //   chapters = new int[from.chapNumber];
  //   copyChapters(from.chapNumber, from.chapters);
  // }else{
  //   delete[] chapters;
  //   chapters = new int[from.chapNumber];
  //   if (from.chapters)  copyChapters(from.chapNumber, from.chapters);
  // }
  return *this;
}



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

const int *Film::getChapters() const { return chapters; }

const int Film::getChapNumber() { return chapNumber; }

void Film::show(ostream &s){
  Video::show(s);
  s << "Chapters duration: "
    << "\n";
  for (int i = 0; i < chapNumber; i++)
  {
    s << "\t Chapter" << i << ": " << chapters[i] << "\n";
  }
}

void Film::copyChapters(int size, const int *chap){
  for (int i = 0; i < size; i++){
    chapters[i] = chap[i];
  }
}