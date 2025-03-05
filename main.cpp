#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

void displayKeyPressed(sf::Keyboard::Key key, sf::RenderWindow &window);
void displayKeyReleased(sf::Keyboard::Key key, sf::RenderWindow &window);

int main(const int argc, [[maybe_unused]] char **argv) {
	if (argc != 1)
		std::cout << "invalid use there is no argument" << std::endl;

	constexpr int offset = 25;

    constexpr unsigned int width = 50 * 21 + 3 * offset;
    constexpr unsigned int height = 50 * 6 + 1 * offset;

	sf::RenderWindow window(sf::VideoMode({width, height}), "Keyboard overlay");

    const sf::Image background_image(sf::Vector2u(width, height), sf::Color(50, 50, 50));
    const sf::Texture background_texture(background_image);
    const sf::Sprite background_sprite(background_texture);

    window.draw(background_sprite);
    window.display();
    window.draw(background_sprite);

	window.setFramerateLimit(60);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
			if (event->is<sf::Event::KeyPressed>())
				displayKeyPressed(event->getIf<sf::Event::KeyPressed>()->code, window);
			if (event->is<sf::Event::KeyReleased>())
				displayKeyReleased(event->getIf<sf::Event::KeyReleased>()->code, window);
		}
	}

	window.clear();
	return (0);
}
