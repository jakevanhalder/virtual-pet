#include "includes.h"
#include "dog.h"
#include "button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Virtual Pet", sf::Style::Titlebar | sf::Style::Close);

    sf::RectangleShape background(sf::Vector2f(500, 500));
    background.setFillColor(sf::Color::Black);

    sf::Vector2f mousePosView; // variable for the mouse and where it is in the window

    // gui
    sf::Font font;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "error loading font from file!!";
    }

    // where you are currently
    button locationPosition(25, 25, 150, 75, &font, "HOME", sf::Color::Yellow,
        sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 0));

    // The current time
    enum class CurrentTime
    {
        DAY,
        NIGHT
    };

    sf::Text currentTime; // going to change this into an icon that will either just be a sun or a moon. It'd be cool to have different phases of the moon as well

    currentTime.setFont(font);
    currentTime.setString("Day");
    currentTime.setCharacterSize(24);
    currentTime.setFillColor(sf::Color::Cyan);
    currentTime.setStyle(sf::Text::Bold);
    currentTime.setPosition(425, 25);
    
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

        // updates where the mouse is in the screen
        mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // Get the elapsed time since the last frame
        sf::Time dt = sf::seconds(1.0f / 60.0f);  // Assuming a frame rate of 60 frames per second

        // Call the updatePosition function to update the dog's position
        dog.updatePosition(dt.asSeconds());

        window.clear();
        window.draw(background);
        locationPosition.update(mousePosView);
        locationPosition.render(&window);
        window.draw(currentTime);
        dog.render(&window);
        window.display();
    }

    return 0;
}