#include <iostream>
#include <thread>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <uiohook.h>

void displayKeyPressed(keyboard_event_data event_data, sf::RenderWindow &window);
void displayKeyReleased(keyboard_event_data event_data, sf::RenderWindow &window);

constexpr int offset = 25;

constexpr unsigned int width = 50 * 21 + 3 * offset;
constexpr unsigned int height = 50 * 6 + 1 * offset;

sf::RenderWindow window(sf::VideoMode({width, height}), "Keyboard overlay");

void onKeyEvent(uiohook_event* event) {
	if (event->type == EVENT_KEY_PRESSED)
		displayKeyPressed(event->data.keyboard, window);
	if (event->type == EVENT_KEY_RELEASED)
		displayKeyReleased(event->data.keyboard, window);
}

int main(const int argc, [[maybe_unused]] char **argv) {
	if (argc != 1)
		std::cout << "invalid use there is no argument" << std::endl;

    const sf::Image background_image(sf::Vector2u(width, height), sf::Color(50, 50, 50));
    const sf::Texture background_texture(background_image);
    const sf::Sprite background_sprite(background_texture);

    window.draw(background_sprite);
    window.display();
    window.draw(background_sprite);
	window.display();

	window.setFramerateLimit(60);

	hook_set_dispatch_proc(onKeyEvent);
	if (hook_run() != UIOHOOK_SUCCESS) {
		std::cout << "error" << std::endl;
		window.close();
	}

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}

	hook_stop();
	window.clear();
	return (0);
}
