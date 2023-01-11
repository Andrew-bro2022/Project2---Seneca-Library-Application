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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem {
	private:
		char* m_content{};

		friend class Menu;
		MenuItem();
		MenuItem(const char* content);
		~MenuItem();
		MenuItem(const MenuItem& toCopy) = delete;
		MenuItem& operator=(const MenuItem& toAssing) = delete;

		operator bool()const;
		operator const char* () const;
		std::ostream& displayMenuItem(std::ostream& ostr = std::cout)const;
	};

	//Menu
	class Menu {
	private:
		MenuItem m_title{};
		MenuItem* m_menuItem[MAX_MENU_ITEMS]{};
		int m_num_menuItem{};

	public:
		Menu();
		Menu(const char* title);
		~Menu();
		Menu(const Menu& toCopy) = delete;
		Menu& operator=(const Menu& toAssing) = delete;

		std::ostream& displayTitle(std::ostream& ostr = std::cout)const;
		std::ostream& displayMenu(std::ostream& ostr = std::cout)const;

		unsigned int run();
		unsigned int operator~();

		Menu& operator<<(const char* menuitemConent);

		//Type conversion operator
		operator int()const;
		operator unsigned int()const;
		operator bool()const;

		const char* operator[](int index)const;

		//Milestone2 new adding function
		void setMenuTitle(const char* title);
	};

	std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
}

#endif // !SDDS_MENU_H