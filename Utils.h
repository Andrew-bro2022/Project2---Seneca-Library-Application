/*
*****************************************************************************
File: Utils.h
Full Name  : Yuchi Zheng
*****************************************************************************
*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include <iostream>

namespace sdds {
   class Utils {

   public:
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      int strcmp(const char* s1, const char* s2)const;

      char* alcpy(const char* cstr);
      void alloCopy(char*& des, const char* value);
      char* getDynCstr(std::istream& istr, char delimiter);
   };

   extern Utils ut;
}

#endif // !SDDS_UTILS_H
