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
			if (a[i][j] == 1) {
				shape.setFillColor(sf::Color::Red);
			}
			shape.setPosition(i * size, j * size);
		
			window.draw(shape);
			shape.setFillColor(sf::Color::Black);

		}

	}
	
}

void Field::Draw(sf::RenderWindow& window) {
	Draw_field(window);
	current.Draw(window);

}


void Field::Save_fig() {

	for (int i = 0; i < current.cells.size(); i++) {
		for (int j = 0; j < current.cells[i].size(); j++) {
			if (current.cells[i][j] == 1) {
				a[i + current.pos.first][j + current.pos.second] = 1;
			}

		}
	}




}
void Field::Move_figure(int direction) {
	current.pos.first +=  direction;
	if (current.pos.first < 0 || current.pos.first + current.cells.size() > a.size()) {
		current.pos.first -= direction;
	}
}

void Field::Move_figure_speed(int num) {
	current.pos.second += num;
	if ( current.pos.second + current.cells[0].size() > a.size()) {
		current.pos.second -= num;
	}
}

void Field::Step() {
	
	
	if (!is_figure_created){
		bool is_all_once;
		for (int j = 0; j < a[0].size(); j++) {
			is_all_once = true;
			for (int i = 0; i < a.size(); i++) {
				if (a[i][j] != 1) {
					is_all_once = false;
				}
			}
			if (is_all_once) {
				for (int i = 0; i < a.size(); i++) {
					a[i][j] = 0;
					
				}
				for (int i = 0; i < a.size(); i++) {
					for (int k = j; k > 0; k--) {
						a[i][k] = a[i][k-1];
					}
				}
				score++;
				return;
			}
		}
		
	}
	bool only_created = false;
	if (!is_figure_created) {
		current = Figure((Type)(rand() % 7));
		/*current = Figure(Type::shape_L);*/
		current.pos.first = 3;
		is_figure_created = true;
		only_created = true;
		
	}

	current.pos.second += 1;

	
	for (int i = 0; i < current.cells.size(); i++) {
		for (int j = 0; j < current.cells[i].size(); j++) {
			if (current.cells[i][j] == 1) {
				if (i + current.pos.first >= a.size() || j + current.pos.second >= a[i].size()) {
					current.pos.second = current.pos.second - 1;
					Save_fig();
					is_figure_created = false;
					return;
				}
				  else if (a[i + current.pos.first][j + current.pos.second] == 1) {
					if (only_created) {
						game_over = true;
						return;
					}
					current.pos.second = current.pos.second - 1;
					Save_fig();
					is_figure_created = false;
					return;

				}
				
			}
		}
		
	}
	


	
}

