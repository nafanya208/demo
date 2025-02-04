#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std; 

enum Type {shape_O , shape_I, shape_S, shape_Z, shape_L, shape_J, shape_T };
class Figure
{
public: 
	sf::Color color;
	pair <float , float > pos;
	vector < vector <int> > cells;
	Figure();
	Figure(Type type);
	void Draw(sf::RenderWindow& window);
	void Turn(); 

};

