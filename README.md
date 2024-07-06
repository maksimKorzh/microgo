# Micro Go
Tiny Go/Baduk/Weiqi playing program with GTP interface

# How it works?
Engine would generate two types of moves - fighting moves
when a group has less than 3 liberties and play away (tenuki) moves.
The latter is an attempt to surround opponents groups one by one.
This is a very naive approach but it might be fun to play with for
absolute beginners.

# How strong is it?
It's slightly stronger than GnuGo1.2, the initial public
release of GnuGo. GnuGo1.2 was meant to be somewhere around
30kyu so MicroGo is about 30kyu as well.

# Related project
If you want just to try it out without downloading/compiling/installing
or learn how it works and find a more readable source code have a look at my
<a href="https://github.com/maksimKorzh/bmgp/tree/main">Bare minimim Go program in JS</a>.
Although that's not the exact copy, still you'll get an idea of how it works.

# How to compile and run it?
Use gcc compiler (mingw on windows), run in
<a href="https://github.com/SabakiHQ/Sabaki/releases">Sabaki GUI</a>
