#include <iostream>
#include <fstream>
#include "city.h"
#include "citylist.h"

int main(){
  string str;
  double x, y;
  int N, K;

  std::ifstream file;
  file.open("tester10.benobogyo");
  file >> N >> K;
  file >> str >> x >> y;

  City* c = new City(str, x, y);
  std::cout << N << " " << K << " ";
  std::cout << *c;
  
  return 0;
}
