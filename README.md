# Micro Go
Tiny Go/Baduk/Weiqi playing program with GTP interface

# How it works?
Engine would generate two types of moves - fighting moves
when a group has less than 3 liberties and play away (tenuki) moves.
The latter is an attempt to surround opponents groups one by one.
This is a very naive approach but it might be fun to play with for
absolute beginners.

# Related project
If you want to learn how it works and find a more readable
source code have a look at my <a href="https://github.com/maksimKorzh/bmgp/tree/main">Bare minimim Go program in JS</a>

# How to compile and run it?
Use gcc compiler (mingw on windows), run in
<a href="https://github.com/SabakiHQ/Sabaki/releases">Sabaki GUI</a>
