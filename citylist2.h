
#ifndef CITYLIST2_HEADER
#define CITYLIST2_HEADER
#include <iostream>
#include "city.h"
using std::string;


//CityList igazából egy City, ami megengedi, hogy két irányba láncolva láncoltlistában legyen
//Minden függvény és változó amit City tud, CityList is tudja, de CityList még tud egy pár láncoltlistás metódust
class CityList2: public City{
CityList2* nextCity;
CityList2* prevCity;
public:
  //Ugyanaz a constructora mint Citynek
  CityList2(const string& cName, int x, int y): City(cName, x, y), nextCity(NULL), prevCity(NULL){};

  //Van egy ilyen constructora is mert miafaszért ne :DD
  CityList2(City* c): City(*c){}

  //Lehet indexelni, de AZ INDEXELÉS GECI LASSÚ úgyh óvatosba :D
  City* operator[](size_t index){
    if(index == 0) return this;
    return (*this)[index - 1];
  }

  //Tulajdonképpen ugyanaz mint az indexelés, csak mással tér vissza
  CityList2* next(size_t index){
      if(index == 0) return this;
      return this->next(index - 1);
  }

  //A paramétereként kapott City-t bekúrja közvetlenül maga után
  void add(City* c){
    CityList2* newCL = new CityList2(c);
    newCL->nextCity = this->nextCity;
    this->nextCity = newCL;
    newCL->prevCity = this;
  }

  //Ugyanazt csinálja mint az add, lehet ezt is használni ha vkinek így jobban tetszik :D
  void operator>>(City* c){
    CityList2* newCL = new CityList2(c);
    newCL->nextCity = this->nextCity;
    this->nextCity = newCL;
    newCL->prevCity = this;
  }

  //Hozzáad egy City-t maga elé (Ugyanaz mint az add csak maga elé)
  void operator<<(City* c){
    CityList2* newCL = new CityList2(c);
    newCL->prevCity = this->prevCity;
    this->prevCity = newCL;
    newCL->nextCity = this;
  }

  ~CityList2(){ delete nextCity; }
};

#endif
