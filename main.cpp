#include <iostream>
#include <fstream>
#include "city.hpp"
#include "citylist.hpp"
#include "helperArray.hpp"

int main(){
  size_t N, K;

  std::ifstream file;
  file.open("tester50.benobogyo");
  file >> N >> K;
  string str;
  double x, y;

  file >> str >> x >> y;
  Array* arr = new Array(N, str, x, y);
  for (size_t i = 0; i < N - 1; i++){
    file >> str >> x >> y;
    arr->push(new City(str, x, y));
  }
  CityList* list;
  for(list = arr->list(); list != nullptr; list = list->next())
    std::cout << *list;
  return 0;
}
