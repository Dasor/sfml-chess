#include <SFML/Graphics.hpp>
#include <iostream>
#define boardsize 800

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(boardsize, boardsize), "My window", sf::Style::Titlebar | sf::Style::Close);

    float squaresize = boardsize/8;
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(squaresize, squaresize));
    sf::Texture boardtexture1;
    boardtexture1.loadFromFile("texture1.jpg");
    sf::Texture boardtexture2;
    boardtexture2.loadFromFile("texture2.jpg");
    short evenline = 0;

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

        square.setTexture(&boardtexture1);
        for(int i = 0; i<8;i++){
          for(int j = 0; j<4;j++){
            square.setPosition((squaresize*2)*j+(squaresize*evenline),squaresize*i);
            window.draw(square);
          }
          if(i%2 == 0){
            evenline = 1;
          }else{
            evenline = 0;
          }
        }

        evenline = 1;

        square.setTexture(&boardtexture2);
        for(int i = 0; i<8;i++){
          for(int j = 0; j<4;j++){
            square.setPosition((squaresize*2)*j+(squaresize*evenline),squaresize*i);
            window.draw(square);
          }
          if(i%2 == 0){
            evenline = 0;
          }else{
            evenline = 1;
          }
        }

        evenline = 0;

        window.display();


    }

    return 0;
}
