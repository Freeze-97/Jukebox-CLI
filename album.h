//
// Created by Admin on 2019-03-13.
// Header-fil förklassen Album

#ifndef PROJECT_ALBUM_H
#define PROJECT_ALBUM_H
#include "song.h"
#include <vector>

class Album {
private:
    string albumName;
    Time totalTime;
    int amountOfSongs = 0;
    vector<Song> songs;
public:
    // Konstruktor
    Album();
    explicit Album(string pAlbumName);

    // Iterator
    vector<Song>::const_iterator begin() const {return songs.begin();}
    vector<Song>::const_iterator end() const {return songs.end();}

    // Set-funktion
    void setAlbumName(string pAlbumName);
    void setSong(Song &song);
    void setAmountOfSongs(int pAmountOfSongs);

    // Get-funktioner
    Time getTotalTime() const {return totalTime;}
    string getAlbumName() const {return albumName;}
    vector<Song> getSongs() const {return songs;}
    int getAmountOfSongs() const {return amountOfSongs;}

    // Operator
    bool operator<(const Album &album) const;
};
// In- och utskrift
ostream &operator<<(ostream &os, const Album &album);
istream &operator>>(istream &is, Album &album);
#endif //PROJECT_ALBUM_H
