/*
*****************************************************************************
File: Streamable.cpp
Full Name  : Yuchi Zheng
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
   std::ostream& operator<<(std::ostream& os, const Streamable& RO) {
      if (RO) {
         RO.wirte(os);
      }
      return os;    
   }

   std::istream& operator>>(std::istream& is, Streamable& RO) {
       return RO.read(is);
   }

}
