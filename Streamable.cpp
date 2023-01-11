/*
*****************************************************************************
                    Milestone #5
Full Name  : Yuchi Zheng
Student ID#: 025 848 151
Email      : yzheng103@myseneca.ca
Section    : NAA
Date       : 7, August, 2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
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