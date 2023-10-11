# Music Playlist Manager

This is a rudimentary program for managing a playlist of songs. It allows you to create, modify, and interact with a playlist of songs. You can add songs, remove songs, change the position of songs, and perform various other operations on the playlist.

## Collaborator

This program was created in collaboration with **Peter Chu** (pchu024).

## Compilation

You can compile the program using the following command:

```bash
g++ Playlist.cpp main.cpp -Wall -Werror -Wuninitialized -o ./a.exe
```

## Usage
1. Run the compiled program `a.exe`.

2. Enter the title for your playlist.

3. Choose from the following menu options:

    - **a** - Add a song to the playlist.
    - **d** - Remove a song from the playlist.
    - **c** - Change the position of a song in the playlist.
    - **s** - Output songs by a specific artist.
    - **t** - Output the total time of the playlist (in seconds).
    - **o** - Output the full playlist.
    - **q** - Quit the program.

## Sample Usage
Here's an example of how to use the program:

1. Enter the title for your playlist: "My Playlist"

2. Choose an option from the menu:

```bash    
    My Playlist PLAYLIST MENU
    a - Add song
    d - Remove song
    c - Change position of song
    s - Output songs by a specific artist
    t - Output total time of playlist (in seconds)
    o - Output full playlist
    q - Quit
```

Enter your choice, e.g., a to add a song, and follow the prompts to input song details.

3. Repeat step 2 to perform additional operations on your playlist.

4. To exit the program, choose **q**.

## Sample Output

```bash
$ ./a
Enter playlist's title:
Hoodrat Sheet

Hoodrat Sheet PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:
a
ADD SONG
Enter song's unique ID:
001
Enter song's name:
Beno!
Enter artist's name:
Playboi Carti
Enter song's length (in seconds):
200

Hoodrat Sheet PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:a

ADD SONG
Enter song's unique ID:
002
Enter song's name:
Teenage Dream
Enter artist's name:
Katy Perry
Enter song's length (in seconds):
260

Hoodrat Sheet PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:o

Hoodrat Sheet - OUTPUT FULL PLAYLIST
1.
Unique ID: 001
Song Name: Beno!
Artist Name: Playboi Carti
Song Length (in seconds): 200

2.
Unique ID: 002
Song Name: Teenage Dream
Artist Name: Katy Perry
Song Length (in seconds): 260

Hoodrat Sheet PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit
```