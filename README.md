# Chess in sfml

## Resolution

Firts if you wish to change the resolution just open the file called `definitions.hpp` and change the line that says `#define boardsize 1000` , in this case 1000 is the width of the window so if you're playing on a 720p monitor you may want to change it to 600 or 700, if also for some reason you're playing on a 4k monitor you probably will want to also change the resolution to fit your prefences or even if you are playing on a 1080p monitor you can change it to 800 if you think 1000 is too big.

## How it works

In my opinion this code suffers from what I like to call **"spaghetti code"** yet I am going to try to explain how it works on the surface.

* Firtsly we have the simplest file, `definitions.hpp` which I spoke about in the resolution section, it is just a bunch of definitions to make the code simpler.
* Secondly we have the `main.cpp` which is just the sfml loop that makes the game work, inside the loop there are some funtions or code to follow the rules of the game.
* We also have the `main.hpp` this is just every function,class or code that I needed to include in `main.cpp`. the header file contains both code from `game.cpp` and `pieces.cpp`.
* In `game.cpp` we have some functions and structures that help both the grapich interface and the "backend".
* And last but not least `pieces.cpp`,here you can find a lot of classes that represent every type of piece, it is made with polymorphism and abstraction so every piece has a unique Move method.

## How to play
this chess is a **2 player version** so there is no AI, to move a piece you just have to click the piece you want to move and then again click the square where you want it to move, en passant and castle are implemented as well as check and pins. Checkmate is also implemented, it just freezes the game because there are no moves left. Only thing left to implement is pawn promotion.



## Bugs or Improvemets

If you find any bug or you think something can be improved (it certainly can) and know how please let me know and I will try my best to apply it regarding my current situation.
