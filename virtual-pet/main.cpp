#include "includes.h"
#include "dog.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Virtual Pet", sf::Style::Titlebar | sf::Style::Close);

    sf::RectangleShape background(sf::Vector2f(500, 500));

    // gui
    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "error loading font from file!!";
    }

    sf::Text currentLocation;

    currentLocation.setFont(font);
    currentLocation.setString("HOME");
    currentLocation.setCharacterSize(24);
    currentLocation.setFillColor(sf::Color::Red);
    currentLocation.setStyle(sf::Text::Bold);


    // pets
    Dog dog(sf::Vector2f(250,250)); // have to rework this so that the position doesn't keep getting set to the middle
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Get the elapsed time since the last frame
        sf::Time dt = sf::seconds(1.0f / 60.0f);  // Assuming a frame rate of 60 frames per second

        // Call the updatePosition function to update the dog's position
        dog.updatePosition(dt.asSeconds());

        window.clear();
        window.draw(background);
        window.draw(currentLocation);
        dog.render(&window);
        window.display();
    }

    return 0;
}