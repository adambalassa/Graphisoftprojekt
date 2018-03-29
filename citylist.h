
#ifndef CITYLIST_HEADER
#define CITYLIST_HEADER
#include <iostream>
#include "city.h"
using std::string;

class CityList: public City{
CityList* nextCity;
CityList* prevCity;
public:
  CityList(const string& cName, int x, int y): City(cName, x, y), nextCity(NULL), prevCity(NULL){};
  CityList(City* c): City(*c){}
  City* operator[](size_t index){
    if(index == 0) return this;
    return (*this)[index - 1];
  }
  CityList* next(size_t index){
      if(index == 0) return this;
      return this->next(index - 1);
  }
  void add(City* c){
    CityList* newCL = new CityList(c);
    newCL->nextCity = this->nextCity;
    this->nextCity = newCL;
    newCL->prevCity = this;
  }
  void operator>>(City* c){
    CityList* newCL = new CityList(c);
    newCL->nextCity = this->nextCity;
    this->nextCity = newCL;
    newCL->prevCity = this;
  }
  void operator<<(City* c){
    CityList* newCL = new CityList(c);
    newCL->prevCity = this->prevCity;
    this->prevCity = newCL;
    newCL->nextCity = this;
  }
  ~CityList(){ delete nextCity; }
};

#endif
