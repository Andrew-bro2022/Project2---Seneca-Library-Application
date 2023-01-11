/*
*****************************************************************************
                    Milestone #4
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

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

namespace sdds {
   Utils ut;

   char* Utils::strcpy(char* des, const char* src) const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }

   int Utils::strlen(const char* str) const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   int Utils::strcmp(const char* s1, const char* s2)const {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }


   char* Utils::alcpy(const char* cstr) {
      char* newStr{};
      if (cstr) {
         newStr = new char[strlen(cstr) + 1];
         strcpy(newStr, cstr);
      }
      return newStr;
   }

   void Utils::alloCopy(char*& des, const char* value) {
      delete[] des;
      des = nullptr;
      if (value) {
         des = new char[strlen(value) + 1];
         strcpy(des, value);
      }
   }

   char* Utils::getDynCstr(std::istream& istr, char delimiter) {
      char* cstr{};
      string str;
      getline(istr, str, delimiter);
      if (istr) cstr = alcpy(str.c_str());
      return cstr;
   }
}