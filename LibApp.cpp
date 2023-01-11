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
#include <fstream>
#include <cstring>
#include "LibApp.h"

using namespace std;

namespace sdds {
	void LibApp::pubTypeMenuInitial() {
		//title set 
		m_pubTypeMenu.setMenuTitle("Choose the type of publication:");//constructor?
		//Menu("Choose the type of publication:");//constructor?

		//menu item set
		m_pubTypeMenu << "Book";
		m_pubTypeMenu << "Publication";
	}

	void LibApp::mainMenuInitial() {
		//title set 
		m_mainMenu.setMenuTitle("Seneca Library Application");

		//menu item set
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
	}

	void LibApp::exitMenuInitial() {
		//title set
		m_exitMenu.setMenuTitle("Changes have been made to the data, what would you like to do?");

		//menu item set
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
	}

	bool LibApp::confirm(const char* message) {	
		Menu confirm(message);		
		confirm << "Yes";

		return confirm.run() == 1;
	}

	void LibApp::load() {					//
		cout << "Loading Data" << endl;
		ifstream infile(m_fileName);	//
		char type{};
		int i;
		for (i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				if (type == 'P')
					m_PPA[i] = new Publication;
				else if (type == 'B')
					m_PPA[i] = new Book;
				if (m_PPA[i]) {
					infile >> *m_PPA[i];
				}
			}
		}
		m_LLRN = (*m_PPA[i - 2]).getRef();		//
		m_NOLP = i - 1;
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;

		if (m_changed == true && !isEmpty()) {			//m_changed = false &&
			ofstream oufile(m_fileName);
			if (oufile) {
				for (int i = 0; i < m_NOLP; i++) {
					if ((*m_PPA[i]).getRef() != 0) {
						oufile << *m_PPA[i] << endl;			//
					}
				}
			}
		}
	}



	void LibApp::search(const char* searchMethod) {
		unsigned int select{}, count{};
		char title[MAX_SEARCH_TITLE_LEN]{};
		char searchType{};
		PublicationSelector ps("Select one of the following found matches:");
		//cout << "Searching for publication" << endl;

		select = m_pubTypeMenu.run();
		if (select == 0)		{cout << "Aborted!" << endl;}
		else if (select == 1) {searchType = 'B';}
		else if (select == 2) {searchType = 'P';}

		if (select == 1 || select == 2) {
			cout << "Publication Title: ";
			cin.getline(title, MAX_SEARCH_TITLE_LEN, '\n');

			for (int i = 0; i < m_NOLP; i++) {
				if (m_PPA[i]->getRef() != 0 && m_PPA[i]->type() == searchType
					&& (strstr(*m_PPA[i], title))) {
					if (ut.strcmp(searchMethod, "all") == 0) {
						ps << m_PPA[i];
						count++;
					}
					else if (ut.strcmp(searchMethod, "onLoan") == 0 && m_PPA[i]->onLoan()) {
						ps << m_PPA[i];
						count++;
					}
					else if (ut.strcmp(searchMethod, "available") == 0 && !(m_PPA[i]->onLoan())) {
						ps << m_PPA[i];
						count++;
					}
				}
			}
			if (count) {
				ps.sort();
				m_libRef = ps.run();
				if (m_libRef == 0) { cout << "Aborted!" << endl << endl; }
			}
			else {
				m_libRef = -1000;
				cout << "No matches found!" << endl << endl;
			}
		}
	}

	Publication* LibApp::getPub(int libRef) {
		bool done = false;
		int i;
		for (i = 0; i < m_NOLP && done == false; i++) {
			if (m_PPA[i]->getRef() == libRef) {
				done = true;
			}
		}
		return m_PPA[i -1];
	}

	
	void LibApp::newPublication() {
		unsigned int select{};
		char type{};
		Publication* temp{};	//important

		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;;
			select = m_pubTypeMenu.run();
			if (select == 0)	{ 
				cout << "Aborted!" << endl << endl; 
			}		
			else if (select == 1) { 
				type = 'B'; 
				temp = new Book;		//important
			}
			else if (select == 2) { 
				type = 'P'; 
				temp = new Publication;		//important
			}

			if (select == 1 || select == 2) {
				cin >> *temp;

				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (type == 'B' && *temp) {
							temp->setRef(++m_LLRN);
							m_PPA[m_NOLP++] = temp;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							temp->setRef(++m_LLRN);
							m_PPA[m_NOLP++] = temp;
							m_changed = true;
							cout << "Publication added" << endl;
						}
					}
					else { cout << "Aborted!"; }
					cout << endl;
				}
				if (!(*m_PPA[m_NOLP - 1])) {		//other attributes restore?
					cout << "Failed to add publication!";
					delete m_PPA[m_NOLP];
					m_PPA[m_NOLP] = nullptr;
					//m_changed = false;
				}
			}
			//cin >> *temp;

			//if (cin.fail()) {
			//	cin.ignore(1000, '\n');
			//	cout << "Aborted!" <<endl;
			//}
			//else {
			//	if (confirm("Add this publication to the library?")) {
			//		if (type == 'B' && *temp) {
			//			temp->setRef(++m_LLRN);
			//			m_PPA[m_NOLP++] = temp;
			//			m_changed = true;
			//			cout << "Publication added" << endl;
			//		}
			//		else {
			//			temp->setRef(++m_LLRN);
			//			m_PPA[m_NOLP++] = temp;
			//			m_changed = true;
			//			cout << "Publication added" << endl;
			//		}
			//	}
			//	else { cout << "Aborted!"; }
			//	cout << endl;
			//}
			//if ( !(*m_PPA[m_NOLP - 1])) {		//other attributes restore?
			//	cout << "Failed to add publication!";
			//	delete m_PPA[m_NOLP];
			//	m_PPA[m_NOLP] = nullptr;
			//	//m_changed = false;
			//}
		}
	}

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		search("all");

		if (m_libRef > 0) {
			getPub(m_libRef)->wirte();
			cout << endl;

			if (confirm("Remove this publication from the library?")) {
				getPub(m_libRef)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
			cout << endl;
		}
	}

	void LibApp::checkOutPub() {
		unsigned int memberNum{};
		bool done{};

		cout << "Checkout publication from the library" << endl;
		search("available");
		if (m_libRef > 0) {
			getPub(m_libRef)->wirte();
			cout << endl;

			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				do {
					//cin.ignore(1000, '\n');
					cin >> memberNum;
					if (cin.fail()) {
						cin.clear();
						cout << "Invalid membership number, try again: ";
						done = false;
					}
					else if (memberNum < 10000 || memberNum > 99999) {
						cout << "Invalid membership number, try again: ";
						done = false;
					}
					else {
						done = true;
					}
					cin.ignore(1000, '\n');
				} while (!done);

				getPub(m_libRef)->set(memberNum);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
			cout << endl;
		}
	}

	void LibApp::returnPub() {
		int delayDyas{};
		float penalty{};
		Publication currentDate{};
		currentDate.resetDate();
		
		cout << "Return publication to the library" << endl;
		search("onLoan");
		if (m_libRef > 0) {
			getPub(m_libRef)->wirte();
			cout << endl;

			if (confirm("Return Publication?")) {
				delayDyas = currentDate.checkoutDate() - getPub(m_libRef)->checkoutDate() - SDDS_MAX_LOAN_DAYS;
				//cout << "temp current day: " << currentDate.checkoutDate() << endl;
				//cout << "getPub(m_libRef)->checkoutDate(): " << getPub(m_libRef)->checkoutDate() << endl;

				if (delayDyas) {
					penalty = PER_DAY_PENALTY * delayDyas;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty << " penalty for being ";
					cout << delayDyas << " days late!" << endl;
					cout.unsetf(ios::fixed);
				}
				getPub(m_libRef)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
			cout << endl;
		}
	}

	bool LibApp::isEmpty() {
		return m_NOLP == 0;
	}

	void LibApp::setEmpty() {
		m_fileName[0] = '\0';
		m_PPA[SDDS_LIBRARY_CAPACITY - 1] = { nullptr };	//0
		m_NOLP = 0;
		m_changed = 0;
		m_libRef = -1;
	}

	void LibApp::setFileName(const char* filename) {
		ut.strcpy(m_fileName, filename);
	}

	//Public members
	LibApp::LibApp() {
		m_changed = false;
		mainMenuInitial();
		exitMenuInitial();
		load();
	}

	LibApp::LibApp(const char* filename) {
		setEmpty();
		m_changed = false;
		setFileName(filename);
		pubTypeMenuInitial();
		mainMenuInitial();
		exitMenuInitial();
		load();
		if (m_NOLP == 0) {
			setEmpty();
			m_changed = true;
		}
		/*else {
			sort();
		}*/
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
	}

	void LibApp::run() {
		bool done = false;
		unsigned int select{};

		do{
			select = m_mainMenu.run();
			if (select == 1)		{ newPublication(); }
			else if (select == 2) { removePublication(); }
			else if (select == 3) { checkOutPub(); }
			else if (select == 4) { returnPub(); }
			else { 
				if (m_changed) {
					select = m_exitMenu.run();
					if (select == 1) {
						save();
						done = true;
					}
					else if (select == 2) {
						cout << endl;
					}
					else {
						if (confirm("This will discard all the changes are you sure?")) {
							done = true;
						}
					}
				}
				else {
					done = true;
				}
			}
		} while (!done);

		cout << endl << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}