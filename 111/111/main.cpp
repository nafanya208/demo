#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field.h"
#include "Figure.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), L"Новый проект", Style::Default);

    window.setVerticalSyncEnabled(true);

    float time = 0;
    Clock clock;

    Field field(10, 10);
    field.Step();
    Figure figure(shape_T);
    /*RectangleShape shape(Vector2f(100, 100));
    shape.setPosition(250, 250);
    shape.setFillColor(Color::White);*/
    Font font;
    font.loadFromFile("arial.ttf");
    Text text("", font, 50);
    text.setPosition(10, 10);
    text.setFillColor(Color::Green);
    Text text_over("", font, 50);
    text_over.setPosition(250, 250);
    text_over.setFillColor(Color::Cyan);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                /*if (event.key.code == Keyboard::E) {
                    shape.setFillColor(Color::Black);
                }
                if (event.key.code == Keyboard::Q) {
                    shape.setFillColor(Color::Blue);
                }*/
                if (event.key.code == Keyboard::A) {
                    field.Move_figure(-1);
                }
                if (event.key.code == Keyboard::D) {
                    field.Move_figure(1);
                }
                if (event.key.code == Keyboard::S) {
                    field.Move_figure_speed(1);
                }
                if (event.key.code == Keyboard::E) {
                     field.current.Turn();
                }
            }
        }

        window.clear(Color::White);

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        text.setString( std::to_string(field.score));
        text_over.setString("GAME OVER");
        
        
        if (field.game_over) {
            window.draw(text_over);
            window.display();
            continue;
        }

        if (time > 100) {
            field.Step();
            time = 0;
        }
        time++;

        field.Draw(window);
     
        window.draw(text);
        window.display();

        

    }
    return 0;
}