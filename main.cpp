#include <iostream>

#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <Windows.h>

void displayKeyPressed(int key, sf::RenderWindow &window, sf::Sprite &sprite);
void displayKeyReleased(int key, sf::RenderWindow &window, sf::Sprite &sprite);

int main(int argc) {
	if (argc != 1)
		std::cout << "invalid use there is no argument" << std::endl;

    int offset = 25;

    unsigned int width = 50 * 21 + 2 * offset;
    unsigned int height = 50 * 6 + 1 * offset;

	sf::RenderWindow window(sf::VideoMode({width, height}), "Keyboard overlay");

    sf::Image background_image(sf::Vector2u(width, height), sf::Color(50, 50, 50));
    sf::Texture background_texture(background_image);
    sf::Sprite background_sprite(background_texture);

    window.draw(background_sprite);
    window.display();
    window.draw(background_sprite);

	window.setFramerateLimit(60);

    bool keys[0xFF] = {false};

    std::vector<sf::Image> key_images;
    std::vector<sf::Texture> key_textures;
    std::vector<sf::Sprite> key_sprites;

    sf::Color released_color;
    sf::Vector2u key_dimension({50u, 50u});

    for (int key = 0; key < 0xFF; key++) {
        key_images.emplace_back(key_dimension, released_color);
        key_textures.emplace_back(key_images[key]);
        key_sprites.emplace_back(key_textures[key]);
    }
    window.draw(key_sprites[49]);

    std::cout << key_images.size() << std::endl;
    std::cout << key_textures.size() << std::endl;
    std::cout << key_sprites.size() << std::endl;

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();

            for (int key = 0; key < 0xFF; key++) {
                SHORT keyState = GetAsyncKeyState(key);

                if (keyState & 0x8000 && !keys[key]) {
                    displayKeyPressed(key, window, key_sprites[key]);
                    window.display();
                    keys[key] = true;
                } else if ((keyState & 0x8000) == 0 && keys[key]) {
                    displayKeyReleased(key, window, key_sprites[key]);
                    window.display();
                    keys[key] = false;
                }
            }
		}
	}

	window.clear();
	return (0);
}