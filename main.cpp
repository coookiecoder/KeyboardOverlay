#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

int main(int argc, char **argv) {
	if (argc != 1)
		std::cout << "invalid use there is no argument" << std::endl;

	sf::RenderWindow window(sf::VideoMode({1000, 200}), "mod1");

	window.setFramerateLimit(60);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}

	window.clear();
	return (0);
}