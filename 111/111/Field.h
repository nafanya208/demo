#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Figure.h"


using namespace std;
class Field
{
public:

	Figure current;
	std::vector <vector <int> > a;
	int high = 10;
	int width = 10;
	Field(int high, int width);

	void Draw_field( sf::RenderWindow& window);

	void Step();
	void Draw(sf::RenderWindow& window);
	
};

