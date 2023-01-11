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

#ifndef SDDS_PUBLICATION_
#define SDDS_PUBLICATION_

#include "Streamable.h"
#include "Date.h"
#include "Lib.h"

namespace sdds {

   class Publication :public Streamable {
   private:
      char* m_title{};  
      char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};      
      int m_membership{};
      int m_libRef = -1;
      Date m_date{}; 

   public:
      Publication();

      //Modifiers
      void setDefault();
      virtual void set(int member_id);
      void setRef(int value);
      void resetDate();

      //Queries
      virtual char type()const;
      bool onLoan()const;
      Date checkoutDate()const;
      bool operator==(const char* title)const;  
      operator const char* ()const;
      int getRef()const;

      //Streamable pure virtual function 
      virtual bool conIO(std::ios& io)const;     
      virtual std::ostream& wirte(std::ostream& os = std::cout)const;
      virtual std::istream& read(std::istream& is = std::cin);
      virtual operator bool()const;

      //Rule of three
      Publication(const Publication& toCopy);
      Publication& operator=(const Publication& toAssign);
      virtual ~Publication();

      //Custom add functions
      void consoleDataRead(std::istream& is, Publication& temp, char* tempTitle);
      void fileDataRead(std::istream& is, Publication& temp, char* tempTitle);
   };
}
#endif // !SDDS_PUBLICATION_
