#include "Field.h"
#include <SFML/Graphics.hpp>


Field::Field(int high, int width) : high(high), width(width) {
	for (int i = 0; i < high; i++) {
		a.push_back(vector <int>());
		for (int j = 0; j < width; j++) {
			a[i].push_back(0);
		}
	}
	srand(time(0));
}

void Field::Draw_field(sf::RenderWindow& window) {
	const float size = 60;
	sf::RectangleShape shape(sf::Vector2f(size - 1, size - 1));
	shape.setPosition(0, 0);
	shape.setFillColor(sf::Color::Black);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			shape.setPosition(i * size, j * size);
			window.draw(shape);

		}

	}
	
}

void Field::Draw(sf::RenderWindow& window) {
	Draw_field(window);
	current.Draw(window);

}

void Field::Step() {
	current = Figure ((Type) (rand() % 10));
	
}

