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
#include <cstring>

#include "Publication.h"
#include "Utils.h"

using namespace std;

namespace sdds {
   Publication::Publication() {
   }

   void Publication::setDefault() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
      m_date.resetCurrDate();       
   }

   //Modifiers
   void Publication::set(int member_id) {
      m_membership = member_id;
   }

   void Publication::setRef(int value) {
      m_libRef = value;
   }

   void Publication::resetDate() {
      m_date.resetCurrDate();     
   }

   //Queries
   char Publication::type() const {
      return 'P';
   }

   bool Publication::onLoan() const {
      return m_membership != 0;
   }

   Date Publication::checkoutDate() const {
      return m_date;    
   }

   bool Publication::operator==(const char* title) const {     
      return  strstr(m_title, title) != nullptr;   
   }

   Publication::operator const char* () const {
      return m_title;
   }

   int Publication::getRef() const {
      return m_libRef;
   }

   //Streamable pure virtual function 
   bool Publication::conIO(std::ios& io) const {
      bool done = false;
      if ((&io == &cin) || (&io == &cout)) { done = true; }
      return  done;
   }

   std::ostream& Publication::wirte(std::ostream& os) const {
      if (conIO(os)) {
         os << "| " << m_shelfId << " | ";

         if (ut.strlen(m_title) <= SDDS_TITLE_WIDTH) {
            os.fill('.');
            os.setf(ios::left);
            os.width(30);
            os << m_title;
            os.fill(' ');
            os.unsetf(ios::left);
         }
         else {
            for (int i = 0; i < SDDS_TITLE_WIDTH; i++) {
               os << m_title[i];
            }
         }

         if (m_membership != 0) {
            os << " | " << m_membership << " | ";
         }
         else {
            os << " | " << " N/A " << " | ";
         }

         m_date.write(os);
         os << " |"; 
      }
      else {      
         os << type() << "\t" << getRef() << "\t" << m_shelfId << "\t";
         os << m_title << "\t" << m_membership << "\t";
         m_date.write(os);
      }
      return os;
   }

   std::istream& Publication::read(std::istream& is) {
      Publication temp{};
      char tempTitle[MAX_TITLE_CHARACTER + 1]{};

      delete[] m_title;
      setDefault();

      if (conIO(is)) {
         consoleDataRead(is, temp, tempTitle);
      }
      else {
         fileDataRead(is, temp, tempTitle);
      }

      if (!is.fail()) {
         m_title = new char[strlen(tempTitle) + 1];
         strcpy(m_title, tempTitle);

         strcpy(m_shelfId, temp.m_shelfId);
         m_membership = temp.m_membership;
         m_libRef = temp.m_libRef;
         m_date = temp.m_date;               
      }
      return is;
   }

   Publication::operator bool() const {      
      return m_title && m_shelfId[0];
   }

   //Rule of three
   Publication::Publication(const Publication& toCopy) {
      operator = (toCopy);
   }

   Publication& Publication::operator=(const Publication& toAssign) {
      if (this != &toAssign && toAssign) {
         delete[] m_title;
         m_title = new char[strlen(toAssign.m_title) + 1];
         strcpy(m_title, toAssign.m_title);

         strcpy(m_shelfId, toAssign.m_shelfId);
         m_membership = toAssign.m_membership;
         m_libRef = toAssign.m_libRef;
         m_date = toAssign.m_date;        
      }
      return *this;
   }

   Publication::~Publication() {
      delete[] m_title;
      m_title = nullptr;
   }

   //Custom add functions
   void Publication::consoleDataRead(istream& is, Publication& temp, char* tempTitle) {
      cout << "Shelf No: ";
      is.getline(temp.m_shelfId, SDDS_SHELF_ID_LEN + 1);
      if (strlen(temp.m_shelfId) != SDDS_SHELF_ID_LEN) {
         is.setstate(ios::failbit);    
      }

      cout << "Title: ";
      is.getline(tempTitle, MAX_TITLE_CHARACTER + 1);

      cout << "Date: ";
      is >> temp.m_date;
      if (temp.m_date.errCode() != 0) {
         is.setstate(ios::failbit);
      }
   }

   void Publication::fileDataRead(std::istream& is, Publication& temp, char* tempTitle) {
      char ch{};

      is >> temp.m_libRef;
      is.get(ch);
      is >> temp.m_shelfId;
      is.get(ch);
      is.getline(tempTitle, MAX_TITLE_CHARACTER + 1, '\t');
      is >> temp.m_membership;
      is.get(ch);
      is >> temp.m_date;
      
      if (temp.m_date.errCode() != 0) {
         is.setstate(ios::failbit);    
      }
   }
}