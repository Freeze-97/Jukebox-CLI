//
// Definitions-fil för klassen menu
// Tommy Yasi
#include "menu.h"

Menu::Menu() {
    menuTitle = " ";
}
Menu::Menu(string pMenuTitle) {
    menuTitle = pMenuTitle;
}
void Menu::setMenuTitle(string pMenuTitle) {
    menuTitle = pMenuTitle;
}
void Menu::addItem(string menuText, bool enabled) {
    MenuItem tmpMenuItem(menuText, enabled);
    menuItems.push_back(tmpMenuItem);
}
void Menu::printMenuItems() {
    cout << menuTitle << endl; // Rubrik
    int i = 1;
    for(auto &e: menuItems) {
        cout << i << ". " << e.getMenuText() << endl;
        i++;
    }
}
int Menu::getMenuChoice() {
    cout << "Choice: " << endl;
    int userChoice;
    cin >> userChoice;
    cin.get();
    return  userChoice;
}