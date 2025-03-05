#include <iostream>
#include <libudev.h>
#include <unordered_map>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <uiohook.h>

#include "SFML/Graphics/Font.hpp"

// Define a map of key positions (QWERTY layout example)
std::unordered_map<uint16_t, sf::Vector2f> keyPositions = {
    // Row 1 (Numbers)
    {VC_1, {50, 75}}, {VC_2, {100, 75}}, {VC_3, {150, 75}},
    {VC_4, {200, 75}}, {VC_5, {250, 75}}, {VC_6, {300, 75}},
    {VC_7, {350, 75}}, {VC_8, {400, 75}}, {VC_9, {450, 75}},
    {VC_0, {500, 75}},

    // Row 2 (QWERTY)
    {VC_Q, {75, 125}}, {VC_W, {125, 125}}, {VC_E, {175, 125}},
    {VC_R, {225, 125}}, {VC_T, {275, 125}}, {VC_Y, {325, 125}},
    {VC_U, {375, 125}}, {VC_I, {425, 125}}, {VC_O, {475, 125}},
    {VC_P, {525, 125}},

    // Row 3 (ASDFG)
    {VC_A, {100, 175}}, {VC_S, {150, 175}}, {VC_D, {200, 175}},
    {VC_F, {250, 175}}, {VC_G, {300, 175}}, {VC_H, {350, 175}},
    {VC_J, {400, 175}}, {VC_K, {450, 175}}, {VC_L, {500, 175}},

    // Row 4 (ZXCV)
    {VC_Z, {100, 225}}, {VC_X, {150, 225}}, {VC_C, {200, 225}},
    {VC_V, {250, 225}}, {VC_B, {300, 225}}, {VC_N, {350, 225}},
    {VC_M, {400, 225}},

    // Special Keys
    {VC_ESCAPE, {0, 0}}, {VC_ENTER, {650, 175}}, {VC_BACKSPACE, {650, 50}},
    {VC_TAB, {0, 125}}, {VC_SPACE, {175, 275}}, {VC_SHIFT_L, {0, 225}},
    {VC_SHIFT_R, {600, 225}}, {VC_CONTROL_L, {0, 275}}, {VC_CONTROL_R, {675, 275}},
    {VC_ALT_L, {125, 275}}, {VC_ALT_R, {575, 275}}, {VC_META_L, {75, 275}},
    {VC_META_R, {625, 275}}, {VC_CONTEXT_MENU, {650, 250}}, {VC_PAGE_UP, {700, 100}},
    {VC_PAGE_DOWN, {700, 150}}, {VC_END, {750, 150}}, {VC_HOME, {750, 100}},

    // Arrow Keys
    {VC_LEFT, {750, 275}}, {VC_RIGHT, {850, 275}},
    {VC_UP, {800, 225}}, {VC_DOWN, {800, 275}},

    // Function Keys (F1 - F12)
    {VC_F1, {75, 0}}, {VC_F2, {125, 0}}, {VC_F3, {175, 0}},
    {VC_F4, {225, 0}}, {VC_F5, {275, 0}}, {VC_F6, {325, 0}},
    {VC_F7, {375, 0}}, {VC_F8, {425, 0}}, {VC_F9, {475, 0}},
    {VC_F10, {525, 0}}, {VC_F11, {575, 0}}, {VC_F12, {625, 0}},

    // Numpad Keys
    {VC_KP_0, {925, 275}}, {VC_KP_1, {925, 225}}, {VC_KP_2, {975, 225}},
    {VC_KP_3, {1025, 225}}, {VC_KP_4, {925, 175}}, {VC_KP_5, {975, 175}},
    {VC_KP_6, {1025, 175}}, {VC_KP_7, {925, 125}}, {VC_KP_8, {975, 125}},
    {VC_KP_9, {1025, 125}},

    // Punctuation & Symbols
    {VC_OPEN_BRACKET, {575, 125}}, {VC_CLOSE_BRACKET, {625, 125}}, {VC_SEMICOLON, {550, 175}},
    {VC_COMMA, {450, 225}}, {VC_PERIOD, {500, 225}}, {VC_QUOTE, {600, 175}},
    {VC_SLASH, {550, 225}}, {VC_BACKSPACE, {675, 125}}, {VC_EQUALS, {600, 75}},
	{VC_MINUS, {850, 225}},

    // Extra Keys
    {VC_INSERT, {800, 125}}, {VC_DELETE, {800, 150}}, {VC_PAUSE, {850, 50}}
};

void displayKeyPressed(const keyboard_event_data event_data, sf::RenderWindow &window) {
    sf::Vector2f position = keyPositions[event_data.keycode];

    const sf::Image key_image(sf::Vector2u(50, 50), sf::Color(100, 100, 100));
    const sf::Texture key_texture(key_image);
    sf::Sprite key_sprite(key_texture);

    key_sprite.setPosition(position);

	sf::Font font("Arial.ttf");
	sf::Text text(font);

	text.setString(static_cast<char>(event_data.rawcode));
	text.setPosition(position);

	std::cout << event_data.rawcode << std::endl;

    window.draw(key_sprite);
	window.draw(text);
    window.display();
}

void displayKeyReleased(const keyboard_event_data event_data, sf::RenderWindow &window) {
	sf::Vector2f position = keyPositions[event_data.keycode];

    const sf::Image key_image(sf::Vector2u(50, 50), sf::Color(50, 50, 50));
    const sf::Texture key_texture(key_image);
    sf::Sprite key_sprite(key_texture);

    key_sprite.setPosition(position);

    window.draw(key_sprite);
    window.display();
}
