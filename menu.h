//
// Header-fil för klassen Menu
// Tommy Yasi

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H
#include "menuItem.h"

class Menu {
private:
    vector<MenuItem> menuItems;
    string menuTitle;
public:
    // Konstruktor
    Menu();
    explicit Menu(string pMenuTitle);

    // Add item
    void addItem(string menuText, bool enabled);

    // Set-funktioner
    void setMenuTitle(string pMenuTitle);

    // Print menu and get menu choices
    void printMenuItems();
    int getMenuChoice();

    // Get-funktioner
    vector<MenuItem> getMenuItems() const {return menuItems;}
    string getMenuTitle()const {return menuTitle;}
};
#endif //PROJECT_MENU_H
