#include <iostream>
#ifndef CITY_HEADER
#define CITY_HEADER
using std::string;

class City{
protected:
  double coordinateX;
  double coordinateY;
  string name;
public:
  City(const string& cName, double x, double y): coordinateX(x), coordinateY(y), name(cName){ }
  City(const City& c): coordinateX(c.coordinateX), coordinateY(c.coordinateY), name(c.name){}
  const int operator-(const City& c) const{
    int x = this->coordinateX - c.coordinateX;
    int y = this->coordinateY - c.coordinateY;
    return x * x + y * y;
  }
  bool operator<(const City& c) const{
    return this->coordinateX < c.coordinateX;
  }
  bool operator>(const City& c) const{
    return this->coordinateX > c.coordinateX;
  }
  City& operator=(const City& c){
    if(&c == this) return *this;;
    this->name = c.name;
    this->coordinateX = c.coordinateX;
    this->coordinateY = c.coordinateY;
    return *this;
  }
  friend std::ostream& operator<<(std::ostream& os, const City& c){
    os << c.name << std::endl;
    return os;
  }
  virtual ~City(){ };
};
#endif
