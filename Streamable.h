/*
*****************************************************************************
File: Streamable.h
Full Name  : Yuchi Zheng
*****************************************************************************
*/


#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>

namespace sdds {
   class Streamable {
   public:
      virtual std::ostream& wirte(std::ostream& os = std::cout)const= 0;
      virtual std::istream& read(std::istream& is = std::cin) = 0;
      virtual bool conIO(std::ios& io)const = 0;
      virtual operator bool()const = 0;
      virtual ~Streamable() {};
   };
   std::ostream& operator<<(std::ostream& os, const Streamable& RO);
   std::istream& operator>>(std::istream& is, Streamable& RO);
}

#endif // !SDDS_STREAMABLE_H
