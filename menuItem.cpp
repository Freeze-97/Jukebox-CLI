//
// Definitions-fil för klassen MenuItem
// Tommy Yasi
#include "menuItem.h"

MenuItem::MenuItem() {
    menuText = " ";
    enabled = false;
}
MenuItem::MenuItem(string pMenuText, bool pEnabled) {
    menuText = pMenuText;
    enabled = pEnabled;
}
MenuItem::~MenuItem() = default;

void MenuItem::setMenuText(string pMenuText) {
    menuText = pMenuText;
}
void MenuItem::setEnabled(bool pEnabled) {
    enabled = pEnabled;
}