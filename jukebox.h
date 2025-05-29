//
// Header-fil för klassen Jukebox

#ifndef PROJECT_JUKEBOX_H
#define PROJECT_JUKEBOX_H
#include <fstream>
#include <algorithm>
#include "menu.h"

class Jukebox {
private:
    vector<Album> albumList;
    Menu menu;
    Menu fileMenu;
    Menu printMenu;

    // Medlemsfunktioner
    void addAlbum();
    void deleteAlbum();
    void file();
    void print();

    // Hjälpfunktioner
    void printSongs(const Album &album);
    vector<Album>::iterator findAlbumByName(const string &searchAlbumName);

    // File undermeny funktioner
    void openFile();
    void saveFile();

    // Print undermeny funktioner
    void printOneAlbum();
    void printAllAlbumsName();
    void printAllAlbumsTime();
    void printOnlyAlbumName();
    void printOnlyAlbumTime();

public:
    Jukebox(); // Default constructor
    void run();

};
const bool compareAlbumName(const Album &a1, const Album &a2);
const bool compareAlbumTime(const Album &a1, const Album &a2);
const void printAlbum(const Album &album);
#endif //PROJECT_JUKEBOX_H
