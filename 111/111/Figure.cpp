#include "Figure.h"

Figure::Figure() {};

Figure::Figure(Type type) {
	if (type == shape_I) {
		color = sf::Color::Red;
		for (int i = 0; i < 4; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 1; j++) {
				cells[i].push_back(1);
			}
		}
	}
	if (type == shape_O) {
		color = sf::Color::Blue;
		for (int i = 0; i < 2; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
	}
	if (type == shape_J) {
		color = sf::Color::Green;
		for (int i = 0; i < 3; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
		cells[0][1] = 0;
		cells[1][1] = 0;


	}if (type == shape_L) {
		color = sf::Color::Yellow;
		for (int i = 0; i < 3; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
		cells[0][0] = 0;
		cells[1][0] = 0;


	}
	if (type == shape_S) {
		color = sf::Color::Cyan;
		for (int i = 0; i < 3; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
		cells[0][0] = 0;
		cells[2][1] = 0;


	}
	if (type == shape_Z) {
		color = sf::Color::Magenta;
		for (int i = 0; i < 3; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
		cells[0][1] = 0;
		cells[2][0] = 0;


	}
	if (type == shape_T) {
		color = sf::Color::Color(234, 119, 242);
		for (int i = 0; i < 3; i++) {
			cells.push_back(vector <int>());
			for (int j = 0; j < 2; j++) {
				cells[i].push_back(1);
			}
		}
		cells[0][1] = 0;
		cells[2][1] = 0;


	}
	

	
};


	void Figure::Draw(sf::RenderWindow& window)  {
		const float size = 60;
		sf::RectangleShape shape(sf::Vector2f(size - 1, size - 1));
		shape.setPosition(0, 0);
		shape.setFillColor(color);
		for (int i = 0; i < cells.size(); i++) {
			for (int j = 0; j < cells[i].size(); j++) {
				if (cells[i][j] != 0) {
					
					shape.setPosition((i + pos.first) * size, (j+ pos.second) * size);
					window.draw(shape);
				}
			}
		}
	}

	void Figure::Turn() {
		vector < vector <int> > new_fig;
		int w = cells[0].size();
		int h = cells.size();
		for (int i = 0; i < w; i++) {
			new_fig.push_back(vector <int>());
			for (int j = 0; j < h; j++) {
				new_fig[i].push_back(0);
			}
		}
		for (int i = 0; i < cells.size(); i++) {
			for (int j = 0; j < cells[0].size(); j++) {
				new_fig[j][i] = cells[i][cells[0].size() - 1 - j];
			}
		}
		cells = new_fig;
	}