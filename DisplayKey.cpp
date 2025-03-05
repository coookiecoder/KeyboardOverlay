#include <iostream>
#include <unordered_map>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

// Define a map of key positions (QWERTY layout example)
#include <SFML/Graphics.hpp>
#include <unordered_map>

// Define a map of key positions (QWERTY layout example)
std::unordered_map<sf::Keyboard::Key, sf::Vector2f> keyPositions = {
    // Row 1 (Numbers)
    {sf::Keyboard::Key::Num1, {50, 75}}, {sf::Keyboard::Key::Num2, {100, 75}}, {sf::Keyboard::Key::Num3, {150, 75}},
    {sf::Keyboard::Key::Num4, {200, 75}}, {sf::Keyboard::Key::Num5, {250, 75}}, {sf::Keyboard::Key::Num6, {300, 75}},
    {sf::Keyboard::Key::Num7, {350, 75}}, {sf::Keyboard::Key::Num8, {400, 75}}, {sf::Keyboard::Key::Num9, {450, 75}},
    {sf::Keyboard::Key::Num0, {500, 75}},

    // Row 2 (QWERTY)
    {sf::Keyboard::Key::Q, {75, 125}}, {sf::Keyboard::Key::W, {125, 125}}, {sf::Keyboard::Key::E, {175, 125}},
    {sf::Keyboard::Key::R, {225, 125}}, {sf::Keyboard::Key::T, {275, 125}}, {sf::Keyboard::Key::Y, {325, 125}},
    {sf::Keyboard::Key::U, {375, 125}}, {sf::Keyboard::Key::I, {425, 125}}, {sf::Keyboard::Key::O, {475, 125}},
    {sf::Keyboard::Key::P, {525, 125}},

    // Row 3 (ASDFG)
    {sf::Keyboard::Key::A, {100, 175}}, {sf::Keyboard::Key::S, {150, 175}}, {sf::Keyboard::Key::D, {200, 175}},
    {sf::Keyboard::Key::F, {250, 175}}, {sf::Keyboard::Key::G, {300, 175}}, {sf::Keyboard::Key::H, {350, 175}},
    {sf::Keyboard::Key::J, {400, 175}}, {sf::Keyboard::Key::K, {450, 175}}, {sf::Keyboard::Key::L, {500, 175}},

    // Row 4 (ZXCV)
    {sf::Keyboard::Key::Z, {100, 225}}, {sf::Keyboard::Key::X, {150, 225}}, {sf::Keyboard::Key::C, {200, 225}},
    {sf::Keyboard::Key::V, {250, 225}}, {sf::Keyboard::Key::B, {300, 225}}, {sf::Keyboard::Key::N, {350, 225}},
    {sf::Keyboard::Key::M, {400, 225}},

    // Special Keys
    {sf::Keyboard::Key::Escape, {0, 0}}, {sf::Keyboard::Key::Enter, {650, 175}}, {sf::Keyboard::Key::Backspace, {650, 50}},
    {sf::Keyboard::Key::Tab, {0, 125}}, {sf::Keyboard::Key::Space, {175, 275}}, {sf::Keyboard::Key::LShift, {0, 225}},
    {sf::Keyboard::Key::RShift, {600, 225}}, {sf::Keyboard::Key::LControl, {0, 275}}, {sf::Keyboard::Key::RControl, {675, 275}},
    {sf::Keyboard::Key::LAlt, {125, 275}}, {sf::Keyboard::Key::RAlt, {575, 275}}, {sf::Keyboard::Key::LSystem, {75, 275}},
    {sf::Keyboard::Key::RSystem, {625, 275}}, {sf::Keyboard::Key::Menu, {650, 250}}, {sf::Keyboard::Key::PageUp, {700, 100}},
    {sf::Keyboard::Key::PageDown, {700, 150}}, {sf::Keyboard::Key::End, {750, 150}}, {sf::Keyboard::Key::Home, {750, 100}},

    // Arrow Keys
    {sf::Keyboard::Key::Left, {750, 275}}, {sf::Keyboard::Key::Right, {850, 275}},
    {sf::Keyboard::Key::Up, {800, 225}}, {sf::Keyboard::Key::Down, {800, 275}},

    // Function Keys (F1 - F12)
    {sf::Keyboard::Key::F1, {75, 0}}, {sf::Keyboard::Key::F2, {125, 0}}, {sf::Keyboard::Key::F3, {175, 0}},
    {sf::Keyboard::Key::F4, {225, 0}}, {sf::Keyboard::Key::F5, {275, 0}}, {sf::Keyboard::Key::F6, {325, 0}},
    {sf::Keyboard::Key::F7, {375, 0}}, {sf::Keyboard::Key::F8, {425, 0}}, {sf::Keyboard::Key::F9, {475, 0}},
    {sf::Keyboard::Key::F10, {525, 0}}, {sf::Keyboard::Key::F11, {575, 0}}, {sf::Keyboard::Key::F12, {625, 0}},

    // Numpad Keys
    {sf::Keyboard::Key::Numpad0, {925, 275}}, {sf::Keyboard::Key::Numpad1, {925, 225}}, {sf::Keyboard::Key::Numpad2, {975, 225}},
    {sf::Keyboard::Key::Numpad3, {1025, 225}}, {sf::Keyboard::Key::Numpad4, {925, 175}}, {sf::Keyboard::Key::Numpad5, {975, 175}},
    {sf::Keyboard::Key::Numpad6, {1025, 175}}, {sf::Keyboard::Key::Numpad7, {925, 125}}, {sf::Keyboard::Key::Numpad8, {975, 125}},
    {sf::Keyboard::Key::Numpad9, {1025, 125}},

    // Punctuation & Symbols
    {sf::Keyboard::Key::LBracket, {575, 125}}, {sf::Keyboard::Key::RBracket, {625, 125}}, {sf::Keyboard::Key::Semicolon, {550, 175}},
    {sf::Keyboard::Key::Comma, {450, 225}}, {sf::Keyboard::Key::Period, {500, 225}}, {sf::Keyboard::Key::Apostrophe, {600, 175}},
    {sf::Keyboard::Key::Slash, {550, 225}}, {sf::Keyboard::Key::Backslash, {675, 125}}, {sf::Keyboard::Key::Grave, {0, 75}},
    {sf::Keyboard::Key::Equal, {600, 75}}, {sf::Keyboard::Key::Hyphen, {550, 75}}, {sf::Keyboard::Key::Add, {900, 250}},
    {sf::Keyboard::Key::Subtract, {850, 225}}, {sf::Keyboard::Key::Multiply, {800, 225}}, {sf::Keyboard::Key::Divide, {750, 225}},

    // Extra Keys
    {sf::Keyboard::Key::Insert, {800, 125}}, {sf::Keyboard::Key::Delete, {800, 150}}, {sf::Keyboard::Key::Pause, {850, 50}}
};

bool keyPressed[100] = {false};

void displayKeyPressed(const sf::Keyboard::Key key, sf::RenderWindow &window) {
    if (key == sf::Keyboard::Key::Unknown || keyPressed[static_cast<int>(key)])
        return;

    sf::Vector2f position = keyPositions[key];

    const sf::Image key_image(sf::Vector2u(50, 50), sf::Color(100, 100, 100));
    const sf::Texture key_texture(key_image);
    sf::Sprite key_sprite(key_texture);

    key_sprite.setPosition(position);

    keyPressed[static_cast<int>(key)] = true;

    window.draw(key_sprite);
    window.display();

    std::cout << position.x << ", " << position.y << " pressed" << std::endl;
}

void displayKeyReleased(const sf::Keyboard::Key key, sf::RenderWindow &window) {
    if (key == sf::Keyboard::Key::Unknown || !keyPressed[static_cast<int>(key)])
        return;

    sf::Vector2f position = keyPositions[key];

    const sf::Image key_image(sf::Vector2u(50, 50), sf::Color(50, 50, 50));
    const sf::Texture key_texture(key_image);
    sf::Sprite key_sprite(key_texture);

    key_sprite.setPosition(position);

    keyPressed[static_cast<int>(key)] = false;

    window.draw(key_sprite);
    window.display();

    std::cout << position.x << ", " << position.y << " released" << std::endl;
}