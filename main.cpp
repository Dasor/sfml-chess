#include <SFML/Graphics.hpp>
#include <iostream>
#include "setup.hpp"
#include "pieces.h"
#define boardsize 800
#define spritesize 150

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "My window", sf::Style::Titlebar | sf::Style::Close);
    int squaresize = boardsize/8;
    BoardRep board = initBoard(squaresize);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        DrawBoard(squaresize,window);
        sf::Texture texture;
        texture.loadFromFile("pieces/bqueen.png");
        texture.setSmooth(true);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(((float)squaresize/spritesize),((float)squaresize/spritesize));
        sprite.setPosition(squaresize,0);
        window.draw(sprite);

        window.display();


    }

    return 0;
}
