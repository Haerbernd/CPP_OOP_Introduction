This is a very basic command line only dungeon crawler game, that I used to learn and apply OOP fundamentals in C++.
I may or may not add to this game later. In case you want to play it, follow the instructions below.

## Building the Game
### Using CMake
1. clone the source code
`git clone https://github.com/Haerbernd/CPP_OOP_Introduction.git`
2. Go into the cloned directory
`cd CPP_OOP_Introduction`
3. Prepare Build System
`cmake .`
4. Build the game
`cmake --build .`
5. Now run "Basic_Dungeon_Crawler"
`./Basic_Dungeon_Crawler`
### Using GCC/G++
1. clone the source code
   `git clone https://github.com/Haerbernd/CPP_OOP_Introduction.git`
2. Go into the cloned directory
   `cd CPP_OOP_Introduction`
3. `g++ main.cpp dungeon.cpp game.cpp gameCharacter.cpp item.cpp player.cpp room.cpp -o Basic_Dungeon_Crawler`
4. Now run "Basic_Dungeon_Crawler"
`./Basic_Dungeon_Crawler`
### Other
Just input all the `.cpp`-files (some compiles may also want the `.h`-files but that shouldn't normally be the case) in a C/C++ Compiler of your choice and your good to go.