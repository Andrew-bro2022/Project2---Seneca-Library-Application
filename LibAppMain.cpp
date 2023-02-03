// LipApp Main
// Full Name  : Yuchi Zheng


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
