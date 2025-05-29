//
// Header-fil förklassen MenuItem

#ifndef PROJECT_MENUITEM_H
#define PROJECT_MENUITEM_H
#include "album.h"

class MenuItem {
private:
    string menuText;
    bool enabled;
public:
    // KOnstruktor
    MenuItem();
    MenuItem(string pMenuText, bool pEnabled);
    ~MenuItem();

    // Set-funktioner
    void setMenuText(string pMenuText);
    void setEnabled(bool pEnabled);

    // Get-funktioner
    string getMenuText() const {return menuText;}
    bool getEnabled() const {return enabled;}
};
#endif //PROJECT_MENUITEM_H
