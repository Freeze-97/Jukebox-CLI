//
// Definitions-fil för klassen Jukebox
// Tommy Yasi
#include "jukebox.h"

const bool compareAlbumTime(const Album &a1, const Album &a2) {
    return a1.getTotalTime() < a2.getTotalTime();
}
const bool compareAlbumName(const Album &a1, const Album &a2) {
    string albumName1 = a1.getAlbumName(), albumName2 = a2.getAlbumName(); // Tilldela albumnamet
    // Ändra alla bokstäver till lowercase
    transform(albumName1.begin(), albumName1.end(), albumName1.begin(), ::tolower);
    transform(albumName2.begin(), albumName2.end(), albumName2.begin(), ::tolower);
    return albumName1 < albumName2;
}

Jukebox::Jukebox() {
    // Huvudmenyn
    menu.setMenuTitle("---- JUKE BOX ----");
    menu.addItem("File...", true);
    menu.addItem("Add an album", false);
    menu.addItem("Delete an album", false);
    menu.addItem("Print...", false);
    menu.addItem("Exit", true);

    // Filemenyn
    fileMenu.setMenuTitle("--- FILE ---");
    fileMenu.addItem("Open", true);
    fileMenu.addItem("Save", false);
    fileMenu.addItem("Back to main menu", true);

    // Printmenyn
    printMenu.setMenuTitle("--- PRINT ---");
    printMenu.addItem("Print one album", false);
    printMenu.addItem("Print all sorted by album name", false);
    printMenu.addItem("Print all sorted by album total time", false);
    printMenu.addItem("Print simple sorted by album name", false);
    printMenu.addItem("Print simple sorted by album total time", false);
    printMenu.addItem("Back to main menu", true);
}
void Jukebox::run() {
    bool again = true;
    do {
        menu.printMenuItems();
        switch(menu.getMenuChoice()) {
            case 1: file();
                break;
            case 2: addAlbum();
                 break;
            case 3: deleteAlbum();
                 break;
            case 4: print();
                 break;
            case 5: again = false;
                break;
            default: cout << "Invalid input!" << endl;
        }
    }while(again);
}
void Jukebox::addAlbum() {
    string tmpAlbumName, tmpTitle, tmpArtist;
    int tmpHour, tmpMinute, tmpSecond;

    cout << "Album name: " << endl;
    getline(cin, tmpAlbumName);
    Album tmpAlbum(tmpAlbumName);

    bool again = true;
    do {
        cout << "Song title: " << endl;
        getline(cin, tmpTitle);
        cout << "Artist: " << endl;
        getline(cin, tmpArtist);

        cout << "Length of song hours: " << endl;
        cin >> tmpHour;
        cout << "Minutes: " << endl;
        cin >> tmpMinute;
        cout << "Seconds: " << endl;
        cin >> tmpSecond;
        cin.get();

        Time tmpLength(tmpHour, tmpMinute, tmpSecond);
        Song tmpSong(tmpTitle, tmpArtist, tmpLength);
        tmpAlbum.setSong(tmpSong);

        cout << "Add one more song?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        switch(menu.getMenuChoice()) {
            case 1: again = true;
                break;
            case 2: again = false;
                break;
            default: cout << "Invalid input!" << endl;
        }
    } while(again);
    albumList.push_back(tmpAlbum);
}
void Jukebox::deleteAlbum() {
    cout << "Name of the album: " << endl;
    string searchAlbumName; // Söknyckel från användaren
    getline(cin, searchAlbumName);
    auto result = findAlbumByName(searchAlbumName);
    if(result != albumList.end()) {
        albumList.erase(result);
    }
    else {
        cout << "The album is not in the list" << endl;
    }
}
void Jukebox::file() {
    bool again = true;
    do {
        fileMenu.printMenuItems();
        switch (fileMenu.getMenuChoice()) {
            case 1: openFile();
                break;
            case 2: saveFile();
                break;
            case 3: again = false;
                break;
            default: cout << "Invalid input!" << endl;
        }

    }while(again);
}
void Jukebox::print() {
    bool again = true;
    do {
        printMenu.printMenuItems();
        switch (printMenu.getMenuChoice()) {
            case 1: printOneAlbum();
                break;
            case 2: printAllAlbumsName();
                break;
            case 3: printAllAlbumsTime();
                break;
            case 4: printOnlyAlbumName();
                break;
            case 5: printOnlyAlbumTime();
                break;
            case 6: again = false;
                break;
            default: cout << "Invalid input!" << endl;
        }

    }while(again);
}
void Jukebox::openFile() {
    albumList.clear();
    const string filename = "jukebox.txt";
    ifstream inf(filename);
    Album tmpAlbumList;
    while(inf >> tmpAlbumList) {
        albumList.push_back(tmpAlbumList);
    }
    inf.close();
    cout << "Read from file!" << endl << endl;
}
void Jukebox::saveFile() {
    const string filename = "jukebox.txt";
    ofstream of(filename.c_str());
    for (const auto &i : albumList) {
        of << i << endl;
    }
    of.close();
    albumList.clear();
    cout << "Saved on file!" << endl << endl;
}
void Jukebox::printOneAlbum() {
    cout << "Name of the album: " << endl;
    string searchAlbumName; // Söknyckel från användaren
    getline(cin, searchAlbumName);

   auto result = findAlbumByName(searchAlbumName);
    if(result != albumList.end()) {
        cout << result -> getAlbumName() << endl;
        cout << "TITLE | ARTIST | LENGTH (hh:mm:ss/mm:ss)" << endl << endl;
        printSongs(*result);
    }
    else {
        cout << "The album is not in the list" << endl;
    }
}
void Jukebox::printAllAlbumsName() {
    sort(albumList.begin(), albumList.end(), compareAlbumName);
    cout << "ALBUM" << endl;
    cout << "TITLE | ARTIST | LENGTH (hh:mm:ss/mm:ss)" << endl << endl;
    for(const auto &album: albumList){
        cout << album.getAlbumName() << endl;
        printSongs(album);
    }
}
void Jukebox::printAllAlbumsTime() {
    sort(albumList.begin(), albumList.end(), compareAlbumTime);
    cout << "ALBUM" << endl;
    cout << "TITLE | ARTIST | LENGTH (hh:mm:ss/mm:ss)" << endl << endl;
    for(const auto &album: albumList){
        cout << album.getAlbumName() << endl;
            printSongs(album);
    }
}
void Jukebox::printOnlyAlbumName() {
    sort(albumList.begin(), albumList.end(), compareAlbumName);
    cout << "--ALBUMS--" << endl;
    for_each(albumList.begin(), albumList.end(), printAlbum);
}
void Jukebox::printOnlyAlbumTime() {
    sort(albumList.begin(), albumList.end(), compareAlbumTime);
    cout << "--ALBUMS--" << endl;
    for(const auto &album: albumList){
        cout << album.getAlbumName() << " | ";
        // Omvandlar till timmar, minuter och sekunder
        int seconds, hours, minutes;
        minutes = album.getTotalTime().getTotalSeconds() / 60;
        seconds = album.getTotalTime().getTotalSeconds() % 60;
        hours = minutes / 60;
        minutes = minutes % 60;

        if(hours > 0) {
            if(minutes > 9 && seconds > 9) {
                cout << hours << ":" << minutes << ":" << seconds << endl;
            }
            else if(minutes < 10 && seconds > 9){
                cout << hours << ":0" << minutes << ":" << seconds << endl;
            }
            else if(minutes > 9 && seconds < 10) {
                cout << hours << ":" << minutes << ":0" << seconds << endl;
            }
            else if(minutes < 10 && seconds < 10) {
                cout << hours << ":0" << minutes << ":0" << seconds << endl;
            }
        }
        else if(hours <= 0) {
            if (seconds > 9) {
                cout << minutes << ":" << seconds << endl;
            }
            else {
                cout << minutes << ":0" << seconds << endl;
            }
        }
    }
}
// Hjälpfunktioner
void Jukebox::printSongs(const Album &album) {
    for (const auto &song: album) {
        cout << song.getTitle() << " " << "|" << " "
             << song.getArtist() << " "  << "|" << " ";

        // Omvandlar till timmar, minuter och sekunder
        int seconds, hours, minutes;
        minutes = song.getLength().getTotalSeconds() / 60;
        seconds = song.getLength().getTotalSeconds() % 60;
        hours = minutes / 60;
        minutes = minutes % 60;

        if(hours > 0) {
            if(minutes > 9 && seconds > 9) {
                cout << hours << ":" << minutes << ":" << seconds << endl;
            }
            else if(minutes < 10 && seconds > 9){
                cout << hours << ":0" << minutes << ":" << seconds << endl;
            }
            else if(minutes > 9 && seconds < 10) {
                cout << hours << ":" << minutes << ":0" << seconds << endl;
            }
            else if(minutes < 10 && seconds < 10) {
                cout << hours << ":0" << minutes << ":0" << seconds << endl;
            }
        }
        else if(hours <= 0) {
            if (seconds > 9) {
                cout << minutes << ":" << seconds << endl;
            }
            else {
                cout << minutes << ":0" << seconds << endl;
            }
        }
    }
    cout << endl;
}
vector<Album>::iterator Jukebox::findAlbumByName(const string &albumName) {
    return find_if(albumList.begin(), albumList.end(),
            [&albumName] (const Album &a1) {return a1.getAlbumName() == albumName;});
}
const void printAlbum(const Album &album) {
    cout << album.getAlbumName() << endl;
}