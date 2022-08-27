#include "../include/game.hpp"


Game* Game::instance = nullptr;


Game* Game::getInstance() {
    if(instance == nullptr)
        instance = new Game();
    return instance;
}


Game::Game()
: window(sf::VideoMode(1280, 720), "SFML works!"),
  view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f)),
  map(sf::Vector2i(256, 256)) {

    mouseButtonHold = false;
    prepareFpsCounter();
}


void Game::handleEvents() {


    static sf::Vector2i oldMousePos;

    sf::Event event;
    while (window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                    view.rotate(1.f);
                    window.setView(view);
                }
                break;
            case sf::Event::MouseButtonPressed:
                oldMousePos = sf::Mouse::getPosition(window);
                mouseButtonHold = true;
                break;
            case sf::Event::MouseButtonReleased:
                mouseButtonHold = false;
                break;
            case sf::Event::MouseMoved:
                if(mouseButtonHold)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i mouseMove = oldMousePos - mousePos;

                    view.move(mouseMove.x, mouseMove.y);
                    window.setView(view);
                    oldMousePos = mousePos;
                    frames.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));
                }
                break;
            case sf::Event::MouseWheelScrolled:
                if(event.mouseWheelScroll.delta > 0)
                {
                    view.zoom(0.98f);
                    frames.scale(0.98f, 0.98f);
                }
                else
                {
                    view.zoom(1.02f);
                    frames.scale(1.02f, 1.02f);
                }
                window.setView(view);
                frames.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));

                break;
            default:
                break;
        }
    }
}

void Game::prepareFpsCounter() {
    font.loadFromFile("./font/Ubuntu-B.ttf");

    frames = sf::Text();
    frames.setFont(font);
    frames.setFillColor(sf::Color::Red);
    frames.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));
    frames.setCharacterSize(24);
    frames.setOutlineColor(sf::Color::White);
    frames.setOutlineThickness(2);
}

void Game::updateFps() {
    currentTime = clock.getElapsedTime();
    fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
    previousTime = currentTime;
    frames.setString(std::to_string(fps));
}

void Game::run() {

    previousTime = clock.getElapsedTime();

    while (window.isOpen()) {
        handleEvents();
        window.clear();
        window.draw(map);

        updateFps();

        window.draw(frames);

        window.display();
    }
}
