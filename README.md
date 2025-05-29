# 🎵 Jukebox
A terminal-based Jukebox application written in C++. It allows users to manage and interact with music albums, each containing multiple songs with detailed time information.

## Key Components

- `main.cpp` – Entry point for the application.
- `jukebox.cpp` / `jukebox.h` – Core class that handles the user interface, menus, and operations like add/delete/print albums.
- `album.cpp` / `album.h` – Represents a music album containing songs.
- `song.cpp` / `song.h` – Represents a single song with title, artist, and duration.
- `theTime.cpp` / `theTime.h` – Custom `Time` class to represent song durations in hh:mm:ss format.
- `menu.cpp` / `menu.h` – General menu functionality.
- `menuItem.cpp` / `menuItem.h` – Represents individual menu items.

## ✅ Features

- 📂 **File operations**  
  - Load albums from a file (`jukebox.txt`)
  - Save albums to a file (`jukebox.txt`)

- ➕ **Add albums**  
  - Input album name, add one or more songs with title, artist, and length

- ❌ **Delete albums**  
  - Remove an album by name

- 🖨️ **Print options**
  - Print a single album with songs
  - Print all albums sorted by name or total time
  - Print only album names sorted by name or time (simple view)
 
## 💾 File Format

Albums and songs are saved to/loaded from `jukebox.txt`. Each album with its songs is serialized and deserialized using overloaded stream operators.

## 🚀 How to Run

1. **Compile the program:**

```bash
g++ -std=c++11 main.cpp jukebox.cpp album.cpp song.cpp theTime.cpp menu.cpp menuItem.cpp -o jukebox
```

2. **Run it:**
```bash
./jukebox
```

3. **Use the menu to interact:**
- Navigate with number inputs

- Add albums and songs

- Save and load from file

- Sort and print albums

## 🛠️ Dependencies
- Standard C++ (tested with C++11 and later)

- No external libraries required

