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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "Publication.h"

namespace sdds {
   class Book :public Publication {
   private:
      char* m_authorName{};
   public:
      Book();
      //Rule of three
      Book(const Book& toCopy);
      Book& operator=(const Book& toAssign);
      virtual ~Book();

      virtual char type()const;
      virtual std::ostream& wirte(std::ostream& os = std::cout)const;
      virtual std::istream& read(std::istream& is = std::cin);
      virtual void set(int member_id);
      virtual operator bool()const;
   };

}
#endif // !SDDS_BOOK_H

