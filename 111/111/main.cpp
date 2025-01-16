#include <SFML/Graphics.hpp>
#include "Field.h"
#include "Figure.h"

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(600, 600), L"Новый проект", Style::Default);


    window.setVerticalSyncEnabled(true);

    Field field(10, 10);
    field.Step();
    Figure figure(shape_T);
    RectangleShape shape(Vector2f( 100 , 100));
    shape.setPosition(250, 250);
    shape.setFillColor(Color::White);
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::E) {
                    shape.setFillColor(Color::Black);
                }
                if (event.key.code == Keyboard::Q) {
                    shape.setFillColor(Color::Blue);
                }
                

            }
               
        }

        window.clear(Color::White);
       /* window.draw(shape);*/

        field.Draw(window);
       
        window.display();
    }
    return 0;
}