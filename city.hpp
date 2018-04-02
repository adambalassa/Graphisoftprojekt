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

  //Leírhatod hogy x = City1 - City2 és visszaadja a távolságukat
  const double operator-(const City& c) const{
    double x = this->coordinateX - c.coordinateX;
    double y = this->coordinateY - c.coordinateY;
    return x * x + y * y;
  }

  //Megmondja melyiknek nagyobb az x coodinátája
  bool operator<(const City& c) const{
    return this->coordinateX < c.coordinateX;
  }
  bool operator<(const double x) const{
    return this->coordinateX < x;
  }
  bool operator>(const City& c) const{
    return this->coordinateX > c.coordinateX;
  }
  bool operator>(const double x) const{
    return this->coordinateX > x;
  }

  //Leírthatod mondjuk, h cities[5] = City2; (City2 City típusú, cities meg City[] típusú)
  City& operator=(const City& c){
    if(&c == this) return *this;;
    this->name = c.name;
    this->coordinateX = c.coordinateX;
    this->coordinateY = c.coordinateY;
    return *this;
  }
  const string& getName() const { return name;}
  //Kiírja a city nevét
  //Leírhatod h cout << City2; és kiírja
  friend std::ostream& operator<<(std::ostream& os, const City& c){
    os << c.name << " ";
    return os;
  }
  virtual ~City(){ };
};
#endif
