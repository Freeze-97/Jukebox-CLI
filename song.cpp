//
// Created by Admin on 2019-03-12.
// Definitionsfil för Song
#include "song.h"

// Funktions-definitioner för klassen Song
Song::Song() {
    title = " ";
    artist = " ";
}
Song::Song(string pTitle, string pArtist, Time pLength) {
    title = pTitle;
    artist = pArtist;
    length = pLength;
}
Song::~Song() = default;

void Song::setTitle(string pTitle) {
    title = pTitle;
}
void Song::setArtist(string pArtist) {
    artist = pArtist;
}
void Song::setTime(Time pLength) {
    length = pLength;
}
const char DELIM = '|';
ostream &operator<<(ostream &os, const Song &song) {
    os << song.getTitle() << DELIM << song.getArtist() << DELIM << song.getLength();
    return os;
}
istream &operator>>(istream &is, Song &song) {
    string tmpTitle, tmpArtist;
    Time tmpLength;

    getline(is, tmpTitle, DELIM);
    song.setTitle(tmpTitle);
    getline(is, tmpArtist, DELIM);
    song.setArtist(tmpArtist);
    is >> tmpLength;
    is.get();
    song.setTime(tmpLength);

    return is;
}