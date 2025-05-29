// Tommy Yasi
// Definitions-fil för klassen Album
#include "album.h"

Album::Album() {
    albumName = " ";
    amountOfSongs = 0;
}
Album::Album(string pAlbumName) {
    albumName = pAlbumName;
}
void Album::setAlbumName(string pAlbumName) {
    albumName = pAlbumName;
}
void Album::setSong(Song &song) {
    totalTime = totalTime + song.getLength();
    amountOfSongs++;
    songs.push_back(song);
}
void Album::setAmountOfSongs(int pAmountOfSongs) {
    amountOfSongs = pAmountOfSongs;
}
bool Album::operator<(const Album &album) const {
    return totalTime < album.totalTime;
}
const char DELIM = '\n';
ostream &operator<<(ostream &os, const Album &album) {
    os << album.getAlbumName() << DELIM;
    os << album.getAmountOfSongs() << DELIM;
    for (const auto &song : album.getSongs()) {
        os << song << DELIM;
    }
    return os;
}
istream &operator>>(istream &is, Album &album) {
    album = Album{};

    string tmpAlbumName;
    getline(is, tmpAlbumName);
    album.setAlbumName(tmpAlbumName);

    int tmpamountOfsongs;
    is >> tmpamountOfsongs;
    is.get();
    for (Song song; tmpamountOfsongs && is >> song; --tmpamountOfsongs) {
        album.setSong(song);
    }
    return is;
}