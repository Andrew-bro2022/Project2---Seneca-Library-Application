// Final Project Milestone 5
// LipApp Main
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

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

//#include "LibApp.h"
//#include "Date.h"
//int main() {
//   sdds::sdds_day = 10;//10
//   sdds::sdds_mon = 8;//12
//   sdds::sdds_year = 2022;//2021
//   sdds::sdds_test = true;
//   sdds::LibApp theApp("LibRecs.txt");
//   theApp.run();
//   return 0;
//}

#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "Date.h"
void runLibApp(const char* filename) {
   char ch{};
   sdds::LibApp theApp(filename);
   theApp.run();
   std::ifstream file(filename);
   while (file) {
      if (file.get(ch)) std::cout << ch;
   }
}
int main() {
   sdds::sdds_day = 10;
   sdds::sdds_mon = 8;
   sdds::sdds_year = 2022;
   sdds::sdds_test = true;
   runLibApp("LibRecs.txt");
   return 0;
}