//#include <SFML/Graphics.hpp>
#include <time.h>

// #include "../include/tileMap/tileMap.hpp"

#include "../include/game.hpp"

int main()
{
    srand(time(NULL));

    // sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    // sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));

    
    // TileMap map(sf::Vector2f(25, 25));

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         if (event.type == sf::Event::KeyPressed)
    //         {
    //             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    //             {
    //                 view.rotate(1.f);
    //                 window.setView(view);
    //             }
    //         }
    //     }


    //     window.clear();
    //     window.draw(map);
    //     window.display();
    // }

    Game* game = Game::getInstance();

    game->run();

    return 0;
}