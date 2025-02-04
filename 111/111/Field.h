#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Figure.h"


using namespace std;
class Field
{
public:
	bool is_figure_created = false;
	Figure current;
	int score;
	bool game_over = false;
	std::vector <vector <int> > a;
	int high = 10;
	int width = 10;
	Field(int high, int width);

	void Draw_field( sf::RenderWindow& window);
	void Move_figure(int direction);
	void Step();
	void Draw(sf::RenderWindow& window);
	void Save_fig();
	void Move_figure_speed(int num);
	
};

