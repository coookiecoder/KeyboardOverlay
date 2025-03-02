#include <iostream>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

void displayKeyPressed(int key, sf::RenderWindow &window, sf::Sprite &sprite) {
    float x = 0;
    float y = 0;

    switch (key) {
//        case 0x30:  x = 500;    y = 75;     break;
//        case 0x31:  x = 50;     y = 75;     break;
//        case 0x32:  x = 100;    y = 75;     break;
//        case 0x33:  x = 150;    y = 75;     break;
//        case 0x34:  x = 200;    y = 75;     break;
//        case 0x35:  x = 250;    y = 75;     break;
//        case 0x36:  x = 300;    y = 75;     break;
//        case 0x37:  x = 350;    y = 75;     break;
//        case 0x38:  x = 400;    y = 75;     break;
//        case 0x39:  x = 450;    y = 75;     break;
        case 0x41: std::cout << "Key: A" << std::endl; break;
        case 0x42: std::cout << "Key: B" << std::endl; break;
        case 0x43: std::cout << "Key: C" << std::endl; break;
        case 0x44: std::cout << "Key: D" << std::endl; break;
        case 0x45: std::cout << "Key: E" << std::endl; break;
        case 0x46: std::cout << "Key: F" << std::endl; break;
        case 0x47: std::cout << "Key: G" << std::endl; break;
        case 0x48: std::cout << "Key: H" << std::endl; break;
        case 0x49: std::cout << "Key: I" << std::endl; break;
        case 0x4A: std::cout << "Key: J" << std::endl; break;
        case 0x4B: std::cout << "Key: K" << std::endl; break;
        case 0x4C: std::cout << "Key: L" << std::endl; break;
        case 0x4D: std::cout << "Key: M" << std::endl; break;
        case 0x4E: std::cout << "Key: N" << std::endl; break;
        case 0x4F: std::cout << "Key: O" << std::endl; break;
        case 0x50: std::cout << "Key: P" << std::endl; break;
        case 0x51: std::cout << "Key: Q" << std::endl; break;
        case 0x52: std::cout << "Key: R" << std::endl; break;
        case 0x53: std::cout << "Key: S" << std::endl; break;
        case 0x54: std::cout << "Key: T" << std::endl; break;
        case 0x55: std::cout << "Key: U" << std::endl; break;
        case 0x56: std::cout << "Key: V" << std::endl; break;
        case 0x57: std::cout << "Key: W" << std::endl; break;
        case 0x58: std::cout << "Key: X" << std::endl; break;
        case 0x59: std::cout << "Key: Y" << std::endl; break;
        case 0x5A: std::cout << "Key: Z" << std::endl; break;
        case 0x20: std::cout << "Key: Space" << std::endl; break;
        case 0x0D: std::cout << "Key: Enter" << std::endl; break;
        case 0x08: std::cout << "Key: Backspace" << std::endl; break;
        case 0x1B: std::cout << "Key: Escape" << std::endl; break;
        case 0x09: std::cout << "Key: Tab" << std::endl; break;
        case 0x10: std::cout << "Key: Shift" << std::endl; break;
        case 0x11: std::cout << "Key: Control" << std::endl; break;
        case 0x12: std::cout << "Key: Alt" << std::endl; break;
        case 0x1C: std::cout << "Key: Enter (Numpad)" << std::endl; break;
        case 0x27: std::cout << "Key: Arrow Right" << std::endl; break;
        case 0x25: std::cout << "Key: Arrow Left" << std::endl; break;
        case 0x28: std::cout << "Key: Arrow Down" << std::endl; break;
        case 0x26: std::cout << "Key: Arrow Up" << std::endl; break;
        default:
            break;
    }
}

void displayKeyReleased(int key, sf::RenderWindow &window, sf::Sprite &sprite) {
    std::cout << "key released" << std::endl;
    return;
}