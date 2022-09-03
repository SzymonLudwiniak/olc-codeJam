#include "../include/game.hpp"
#include "../include/defines.hpp"


Game* Game::instance = nullptr;

Game* Game::getInstance() {
    if(instance == nullptr)
        instance = new Game();
    return instance;
}


Game::Game()
: view(sf::FloatRect(0.f, 0.f, SCREENWIDTH, SCREENHEIGHT)),
  map(sf::Vector2i(1024, 1024), view) {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window = new sf::RenderWindow(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT),
           "OLC::CODEJAM", sf::Style::Default, settings);
    follower = new King(true);
    king = new King(true);
    banner = new Banner(sf::Vector2f(100, 100));
    window->setFramerateLimit(244);
    zoom = 1.f;
    mouseButtonHold = false;

    king->Entity::move(sf::Vector2f(200.f, 200.f));
    follower->setDestination(king);
    mapManager.setTileMap(&map);

    Wind::loadWindTexture();

    wind = new Wind(sf::Vector2f(100.f, 100.f),
                    sf::Vector2f(200.f, 100.f));

    lightning = nullptr;

    entities.push_back(king);
    entities.push_back(follower);
    entities.push_back(banner);
    prepareFpsCounter();
}


void Game::handleEvents() {


    static sf::Vector2i oldMousePos;

    bool moved = false;

    sf::Event event;
    while (window->pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
                    view.rotate(1.f);
                    window->setView(view);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                    mapManager.breakTile(sf::Vector2i(window->mapPixelToCoords(sf::Mouse::getPosition(*window))));
                    if(lightning != nullptr) {
                        delete lightning;
                        lightning = nullptr;
                    }
                    lightning = new Lightning(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
                }
                break;
            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    oldMousePos = sf::Mouse::getPosition(*window);
                    wind->adjustTo(
                            window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
                    mouseButtonHold = true;
                }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    banner->setPosition(
                            window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
                    king->setDestination(banner);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    mouseButtonHold = false;
                }
                break;
            case sf::Event::MouseMoved:
                if(mouseButtonHold) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    sf::Vector2i mouseMove = oldMousePos - mousePos;

                    if(view.getCenter().x - view.getSize().x/2 + mouseMove.x < 0 ||
                    view.getCenter().x + view.getSize().x/2 + mouseMove.x > (map.getSize().x-3)*TILEWIDTH)
                        mouseMove.x = 0;
                    if(view.getCenter().y - view.getSize().y/2 + mouseMove.y < 0 ||
                    view.getCenter().y + view.getSize().y/2 + mouseMove.y > (map.getSize().y-3)*TILEHEIGHT)
                        mouseMove.y = 0;

                    view.move(mouseMove.x, mouseMove.y);
                    moved = true;
                    window->setView(view);
                    oldMousePos = mousePos;
                    frames.setPosition(window->mapPixelToCoords(sf::Vector2i(0, 0)));
                }
                break;
//            case sf::Event::MouseWheelScrolled:
//                if(event.mouseWheelScroll.delta > 0 && zoom > 0.5f) {
//                    view.zoom(0.98f);
//                    frames.scale(0.98f, 0.98f);
//                    zoom *= 0.98f;
//                    map.prepareVisibleTiles();
//                    window.setView(view);
//                }
//                else if (event.mouseWheelScroll.delta < 0 && zoom < 5.f) {
//                    view.zoom(1.02f);
//                    frames.scale(1.02f, 1.02f);
//                    zoom *= 1.02f;
//                    map.prepareVisibleTiles();
//                    window.setView(view);
//                }
//
//                if(view.getCenter().x - view.getSize().x/2 < 0 ||
//                   view.getCenter().y - view.getSize().y/2 < 0)
//                    view.setViewport(sf::FloatRect(0, 0, view.getViewport().height, view.getViewport().width));
//
//                frames.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));
//                break;
            default:
                break;
        }

    }
    if(moved)
    {
        map.prepareVisibleTiles();
        moved = false;
        window->setView(view);
    }
}

void Game::prepareFpsCounter() {
    font.loadFromFile("./font/Ubuntu-B.ttf");

    frames = sf::Text();
    frames.setFont(font);
    frames.setFillColor(sf::Color::Red);
    frames.setPosition(window->mapPixelToCoords(sf::Vector2i(0, 0)));
    frames.setCharacterSize(24);
    frames.setOutlineColor(sf::Color::White);
    frames.setOutlineThickness(2);
}

void Game::updateFps() {
    currentTime = clock.getElapsedTime();
    deltaTime = currentTime.asSeconds() - previousTime.asSeconds();
    fps = 1.0f / deltaTime;
    previousTime = currentTime;
    frames.setString(std::to_string(fps));
}

void Game::run() {

    previousTime = clock.getElapsedTime();

    sf::Texture texture;
    texture.loadFromFile("./textures/banner2.png");

    banner->setTexture(&texture);


    while (window->isOpen()) {
        handleEvents();
        window->clear();
        king->move(deltaTime);
        follower->move(deltaTime);
        wind->blow(entities, deltaTime);
        window->draw(map);
        window->draw(*king);
        window->draw(*follower);
        window->draw(*banner);
        window->draw(*wind);
        if(lightning != nullptr) {
            lightning->rise();
            window->draw(*lightning);
        }
        updateFps();
        window->draw(frames);

        window->display();
    }
}
