
#ifndef CITYLIST_HEADER
#define CITYLIST_HEADER
#include <iostream>
#include "city.hpp"
using std::string;


//CityList igazából egy City, ami megengedi, hogy két irányba láncolva láncoltlistában legyen
//Minden függvény és változó amit City tud, CityList is tudja, de CityList még tud egy pár láncoltlistás metódust
class CityList: public City{

  CityList* nextCity;
  //Ugyanazt csinálja mint az add, lehet ezt is használni ha vkinek így jobban tetszik :D
  CityList* operator>>(const City* c){
    CityList* newCL = new CityList(c);
    newCL->nextCity = this->nextCity;
    this->nextCity = newCL;
    return newCL;
  }
public:
  //Ugyanaz a constructora mint Citynek
  CityList(const string& cName, int x, int y): City(cName, x, y), nextCity(NULL){};

  //Van egy ilyen constructora is mert miafaszért ne :DD
  CityList(const City* c): City(*c){}

  //Lehet indexelni, de AZ INDEXELÉS GECI LASSÚ úgyh óvatosba :D
  City* operator[](size_t index){
    if(index == 0) return this;
    return (*(this->nextCity))[index - 1];
  }

  //Tulajdonképpen ugyanaz mint az indexelés, csak mással tér vissza
  CityList* next(){ return this->nextCity; }

  CityList* append(const City* what){
    CityList* ptr, *prev = nullptr;
    for(ptr = this; ptr != nullptr && *ptr < *what; prev = ptr, ptr = ptr->nextCity);
    return *prev >> what;
  }

  void push(CityList* what){
    this->nextCity = what;
  }

  ~CityList(){ delete nextCity; }
};

#endif
