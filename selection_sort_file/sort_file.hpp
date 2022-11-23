// Do not change
#include <iostream>
#include <fstream>


#include <list>
#include <vector>
#include <deque>

#include "my_sort.hpp"

// Change here
// All occurences of XXX need to be replaced with
// something more meaningful


template<class X, class Y>
void read_file_to_cont(std::ifstream& f, Y& c) {
  X res;
  while (f >> res) {
    c.push_back(res);
  }

}

template<class X, class Y>
void read_and_sort(std::ifstream& fi, std::ofstream& fo) {
  Y res = {};
  read_file_to_cont<X, Y>(fi, res);
  my_selection_sort(res.begin(), res.end());
    for (auto &i : res)
    {
        fo << i << std::endl;
    }
}

template<class X>
void read_and_sort_decide_container(std::ifstream& fi, std::ofstream& fo) {
  char cp;
  fi >> cp;
  fo << cp << std::endl;
  switch(cp)
  {
    case 'd':
      read_and_sort<X, std::deque<X>>(fi, fo);
      break;
    case 'l':
      read_and_sort<X, std::list<X>>(fi, fo);
      break;
    case 'v':
      read_and_sort<X, std::vector<X>>(fi, fo);
      break;
    default:
      throw std::runtime_error("wrong type");
  }
}

void read_and_sort_decide_valuetype(std::ifstream& fi, std::ofstream& fo) {
  char cv;
  fi >> cv;
  fo << cv << std::endl;
  switch(cv) {
    case 'i':
      read_and_sort_decide_container<int>(fi, fo);
      break;
    case 'd':
      read_and_sort_decide_container<double>(fi, fo);
      break;
    case 'u':
      read_and_sort_decide_container<unsigned>(fi, fo);
      break;
    case 'f':
      read_and_sort_decide_container<float>(fi, fo);
      break;
    
    case 's':
      read_and_sort_decide_container<std::string>(fi, fo);
      break;
    case 'c':
      read_and_sort_decide_container<char>(fi, fo);
      break;
    
    default:
      throw std::runtime_error("Error: wrong type");
  }
}



