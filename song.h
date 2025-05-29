//
// Created by Admin on 2019-03-12.
// Header för klassen Song

#ifndef PROJECT_SONG_H
#define PROJECT_SONG_H

#include "theTime.h"

class Song{
private:
    string title, artist;
    Time length;

public:
    // Konstruktor
    Song();
    Song(string pTitle, string pArtist, Time pLength);
    ~Song();

    // Set-Funktioner
    void setTitle(string pTitle);
    void setArtist(string pArtist);
    void setTime(Time pLength);

    // Get-Funktioner
    string getTitle() const {return title;}
    string getArtist() const {return artist;}
    Time getLength() const {return length;}
};
// In- och utskrift
ostream &operator<<(ostream &os, const Song &song);
istream &operator>>(istream &is, Song &song);
#endif //PROJECT_SONG_H
