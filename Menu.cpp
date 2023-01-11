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

#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	//MenuItem
	MenuItem::MenuItem() {
	}

	MenuItem::MenuItem(const char* content) {
		if (content && content[0]) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
	}

	MenuItem::~MenuItem() {		//
		delete[] m_content;
		m_content = nullptr;
	}

	MenuItem::operator bool() const {
		bool ret = false;

		if (m_content && m_content[0]) {
			ret = true;
		}
		return ret;
	}

	MenuItem::operator const char* () const {
		return m_content;
	}

	std::ostream& MenuItem::displayMenuItem(std::ostream& ostr) const {
		if (*this) {
			ostr << m_content;
		}
		return ostr;
	}


	//Menu
	Menu::Menu() {
	}

	Menu::Menu(const char* title) {
		if (title && title[0]) {
			m_title.m_content = new char[strlen(title) + 1];
			strcpy(m_title.m_content, title);
		}
	}

	Menu::~Menu() {
		for (int i = 0; i < m_num_menuItem; i++) {		//
			delete m_menuItem[i];
			m_menuItem[i] = nullptr;
		}
	}

	std::ostream& Menu::displayTitle(std::ostream& ostr) const {
		if (m_title) {
			return ostr << m_title.m_content;
		}
		return ostr;
	}

	std::ostream& Menu::displayMenu(std::ostream& ostr) const {
		displayTitle();
		ostr << endl;

		for (int i = 0; i < m_num_menuItem; i++) {
			ostr << ' ' << i + 1 << "- " << m_menuItem[i]->m_content << endl;
		}
		ostr << " 0- Exit" << endl;
		ostr << "> ";

		return ostr;
	}

	unsigned int Menu::run() {
		unsigned int select{};
		bool done{};

		displayMenu();
		do {
			cin >> select;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Selection, try again: ";
				done = false;
			}
			else if (select < 0 || select >(unsigned int)m_num_menuItem) {
				cout << "Invalid Selection, try again: ";
				done = false;
			}
			else {
				done = true;
			}
			cin.ignore(1000, '\n');
		} while (!done);

		return select;
	}

	unsigned int Menu::operator~() {
		unsigned int select{};
		bool done{};

		displayMenu();
		do {
			cin >> select;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Selection, try again: ";
				done = false;
			}
			else if (select < 0 && select > m_num_menuItem) {
				cout << "Invalid Selection, try again: ";
				done = false;
			}
			else {
				done = true;
			}
			cin.ignore(1000, '\n');
		} while (!done);

		return select;
	}

	Menu& Menu::operator<<(const char* menuitemConent) {	//
		if (m_num_menuItem < (int)MAX_MENU_ITEMS) {
			if (menuitemConent && menuitemConent[0]) {
				char* temp;
				temp = new char[strlen(menuitemConent) + 1];
				strcpy(temp, menuitemConent);

				m_menuItem[m_num_menuItem] = new MenuItem;
				m_menuItem[m_num_menuItem]->m_content = temp;
				m_num_menuItem++;
			}
		}
		return *this;
	}

	Menu::operator int() const {
		return m_num_menuItem;
	}

	Menu::operator unsigned int() const {
		return (unsigned int)m_num_menuItem;
	}

	Menu::operator bool() const {
		return m_num_menuItem > 0;
	}

	const char* Menu::operator[](int index) const {
		return m_menuItem[index % m_num_menuItem]->m_content;
	}

	//Milestone2 new adding function
	void Menu::setMenuTitle(const char* title) {
		if (title && title[0]) {
			delete[] m_title.m_content;
			m_title.m_content = new char[strlen(title) + 1];
			strcpy(m_title.m_content, title);
		}
	}

	std::ostream& operator<<(std::ostream& ostr, const Menu& menu) {
		menu.displayTitle();
		return ostr;
	}

}