#ifndef ARRAY_HEADER
#define ARRAY_HEADER
#include "citylist.hpp"
class Array{
private:
  const unsigned int maxSize;
  size_t first;
  size_t last;
  CityList** cities;
  CityList* firstCity;

  size_t search(const City* x)const{
    size_t next, top = last, bottom = first;
    while(top - bottom != 1)
      if(*x > *cities[next = (top + bottom) / 2]) {
        bottom = next;
      }
      else top = next;
    return bottom;
  }

public:
  Array(int N, const string& cName, int x, int y): maxSize(N), cities(new CityList*[maxSize]), firstCity(new CityList(cName, x, y)){
     first = (last = (N / 2)) - 1;
     cities[first] = firstCity;
   }

  void push(const City* c){
    size_t index = search(c);
    if(*c < *firstCity){
      CityList* cl = new CityList(c);
      cl->push(firstCity);
      if(first > 0) cities[--first] = cl;
      firstCity = cl;
    }
    else if(index == last - 1){
      CityList* cl = cities[index]->append(c);
      if(last < maxSize) cities[last++] = cl;
    }
    else if(index == first){
      firstCity->append(c);
    }
    else
      cities[index]->append(c);

  }

  CityList* list() const { return firstCity; }
};

#endif
