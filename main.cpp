#include <SFML/Graphics.hpp>
#include <iostream>
#include "setup.h"
#define boardsize 800

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "My window", sf::Style::Titlebar | sf::Style::Close);

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

        /*sf::Texture texture;
        texture.loadFromFile("image.png");
        texture.setSmooth(true);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.scale(sf::Vector2f(0.13f, 0.13f));
        window.draw(sprite);*/

        DrawBoard(boardsize/8,window);

        window.display();


    }

    return 0;
}
