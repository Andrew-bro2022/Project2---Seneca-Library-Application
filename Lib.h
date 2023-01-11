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

#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds {
   const int SDDS_MAX_LOAN_DAYS = 15;
   // maximum number of day a publication can be borrowed with no penalty
   const int SDDS_TITLE_WIDTH = 30;
   // The width in which the title of a publication should be printed on the console
   const int SDDS_AUTHOR_WIDTH = 15;
   // The width in which the author name of a book should be printed on the console
   const int SDDS_SHELF_ID_LEN = 4;
   // The width in which the shelf id of a publication should be printed on the console
   const int SDDS_LIBRARY_CAPACITY = 333;//5000
   // Maximum number of publications the library can hold.

   //Custom const variables
   const int MAX_TITLE_CHARACTER = 255;
   //Maximum number of characters of the publication tile 
   const int MAX_AUTHOR_WIDTH = 256;
   //Maximum number of characters of the author name
   const int MAX_DATA_FILE_NAME = 256;
   //Maximum number of characters of the DATA FILE NAME
   const int MAX_SEARCH_TITLE_LEN = 256;
   //Maximum number of characters of the search title's length

   const float PER_DAY_PENALTY = 0.5;
   //A 50 cents per day penalty
}

#endif // !SDDS_LIB_H
