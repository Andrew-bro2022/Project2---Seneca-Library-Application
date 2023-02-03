/*
*****************************************************************************
Book.cpp
Full Name  : Yuchi Zheng
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Book.h"
#include "Lib.h"
#include "Utils.h"

using namespace std;

namespace sdds {
   Book::Book() {
   }

   //Rule of three
   Book::Book(const Book& toCopy) {
      operator = (toCopy);
   }

   Book& Book::operator=(const Book& toAssign) {
      if (this != &toAssign) {
         Publication::operator=(toAssign);

         delete[] m_authorName;
         m_authorName = ut.alcpy(toAssign.m_authorName);
      }
      return *this;
   }

   Book::~Book() {
      delete[] m_authorName;
      m_authorName = nullptr;
   }

   char Book::type() const {
      return 'B';
   }

   std::ostream& Book::wirte(std::ostream& os) const {
      Publication::wirte(os);
      if (conIO(os)) {
         os << ' ';
         if (ut.strlen(m_authorName) <= SDDS_AUTHOR_WIDTH) {
            os.setf(ios::left);
            os.width(SDDS_AUTHOR_WIDTH);
            os << m_authorName;
            os.unsetf(ios::left);
         }
         else {
            for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++) {
               os << m_authorName[i];
            }
         }
         os << " |";
      }
      else {
         os << "\t" << m_authorName;
      }
      return os;
   }

   std::istream& Book::read(std::istream& is) {
      char tempName[MAX_AUTHOR_WIDTH]{};

      Publication::read(is);
      delete[] m_authorName;  

      if (conIO(is)) {
         is.ignore();
         cout << "Author: ";
         //is.getline(tempName, MAX_AUTHOR_WIDTH); ->getline will eat the '\n'
         is.get(tempName, MAX_AUTHOR_WIDTH);
      }
      else {
         is.ignore();
         //is.getline(tempName, MAX_AUTHOR_WIDTH); ->getline will eat the '\n'
         is.get(tempName, MAX_AUTHOR_WIDTH);
      }

      if (is) {
         ut.alloCopy(m_authorName, tempName);
      }
      return is;
   }

   void Book::set(int member_id) {
      Publication::set(member_id);
      resetDate();
   }

   Book::operator bool() const {
      return m_authorName && m_authorName[0] && Publication::operator bool();
   }


}
