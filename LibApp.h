/*
*****************************************************************************
File: LibApp.h
Full Name  : Yuchi Zheng
*****************************************************************************
*/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <iostream>

#include "Menu.h"
#include "Lib.h"
#include "Book.h"
#include "Menu.h"
#include "Utils.h"
#include "PublicationSelector.h"

namespace sdds {

	class LibApp {
	private:
		char m_fileName[MAX_DATA_FILE_NAME]{};	//256
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};	//publication Pointers array 5000
		int m_NOLP{};											//Number Of Loaded Publications
		int m_LLRN{};											//Last Library Reference Number
		bool m_changed{};
		int m_libRef = -1;

		Menu m_pubTypeMenu{};
		Menu m_mainMenu{};		
		Menu m_exitMenu{};

		void pubTypeMenuInitial();
		void mainMenuInitial();
		void exitMenuInitial();

		bool confirm(const char* message);	
		void load();
		void save();
		void search(const char* searchMethod);
		Publication* getPub(int libRef);

		void newPublication();
		void removePublication();
		void checkOutPub();
		void returnPub();

		bool isEmpty();
		void setEmpty();
		void setFileName(const char* filename);
		//void sort();

	public:
		LibApp();
		LibApp(const char* filename);
		~LibApp();		//for() new
		void run();

	};
}

#endif // !SDDS_LIBAPP_H
