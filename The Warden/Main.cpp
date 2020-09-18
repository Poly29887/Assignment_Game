#include<SFML/Graphics.hpp>
#include<iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "The Warden" ,sf::Style::Close|sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(200,200));
	player.setPosition(440.0f, 260.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Test pic/triangle_PNG30.png");
	player.setTexture(&playerTexture);
	while (window.isOpen())
	{
		sf::Event evnt;
		
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std:: cout << "New window width : " << evnt.size.width << "  New window height : " << evnt.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				printf("%c",evnt.text.unicode);
				break;
			}
           
		}

		window.clear();
		window.draw(player);
		window.display();
	}
	return 0;
}

