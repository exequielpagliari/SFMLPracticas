// Include important libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
// Make code easier to type with "using namespace"
using namespace sf;
// This is where our game starts from
int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::None);


	//GameInit

			//Creada Textura de Fondo
	Texture textureBackground;
	//Carga de Textutra de archivo
	textureBackground.loadFromFile("../graphics/background.png");
	//Creacci�n de Sprite
	Sprite spriteBackground;
	//Carga de Textura en el Sprite
	spriteBackground.setTexture(textureBackground);
	//Seteo de posici�n del Sprite
	spriteBackground.setPosition(0, 0);

	Texture textureTree;

	textureTree.loadFromFile("../graphics/tree.png");

	Sprite spriteTree;

	spriteTree.setTexture(textureTree);

	spriteTree.setPosition(810, 0);

	Texture beeTexture;

	beeTexture.loadFromFile("../graphics/bee.png");

	Sprite spriteBee;

	spriteBee.setTexture(beeTexture);

	spriteBee.setPosition(0, 800);

	bool beeActive = false;

	float beeSpeed = 0.0f;

	Texture cloudTexture;

	cloudTexture.loadFromFile("../graphics/cloud.png");

	Sprite spriteCloud1;

	Sprite spriteCloud2;

	Sprite spriteCloud3;

	spriteCloud1.setTexture(cloudTexture);

	spriteCloud2.setTexture(cloudTexture);

	spriteCloud3.setTexture(cloudTexture);

	spriteCloud1.setPosition(0, 0);

	spriteCloud2.setPosition(0, 250);

	spriteCloud3.setPosition(0, 500);


	bool cloud1Active = false;

	bool cloud2Active = false;

	bool cloud3Active = false;


	float cloud1Speed = 0.0f;

	float cloud2Speed = 0.0f;

	float cloud3Speed = 0.0f;

	Clock clock;
	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update the scene
		****************************************
		*/

		Time dt = clock.restart();

		//Configurar bee
		if (!beeActive)
		{
			//configurar velocidad de abeja
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 200;
			std::cout << beeSpeed << std::endl;
			//configurar altura de abeja
			srand((int)time(0) * 10);
			float heigth = (rand() % 500) + 500;
			spriteBee.setPosition(2000, heigth);
			std::cout << heigth << std::endl;
			beeActive = true;
		}
		else
		{
			
			spriteBee.setPosition(spriteBee.getPosition().x - 
				(beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
			
			if (spriteBee.getPosition().x < -100)
				beeActive = false;
		}


		//Manejo de nuves
		//Nube 1

		if (!cloud1Active)
		{
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);

			srand((int)time(0) * 10);
			float heigth = (rand() % 150);
			spriteCloud1.setPosition(-200, heigth);
			cloud1Active = true;
		}
		else
		{
			spriteCloud1.setPosition(spriteCloud1.getPosition().x
				+ (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

			if (spriteCloud1.getPosition().x > 1920)
				cloud1Active = false;
		}


		//Nube 2
		if (!cloud2Active)
		{
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);

			srand((int)time(0) * 20);
			float heigth = (rand() % 300) - 150;
			spriteCloud2.setPosition(-200, heigth);
			cloud2Active = true;
		}
		else
		{
			spriteCloud2.setPosition(spriteCloud2.getPosition().x
				+ (cloud1Speed * dt.asSeconds()), spriteCloud2.getPosition().y);

			if (spriteCloud2.getPosition().x > 1920)
				cloud2Active = false;
		}


		//Nube 3
		if (!cloud3Active)
		{
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200);

			srand((int)time(0) * 30);
			float heigth = (rand() % 450) - 150;
			spriteCloud3.setPosition(-200, heigth);
			cloud3Active = true;
		}
		else
		{
			spriteCloud3.setPosition(spriteCloud3.getPosition().x
				+ (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);

			if (spriteCloud3.getPosition().x > 1920)
				cloud3Active = false;
		}

		/*
		****************************************
		Draw the scene
		****************************************
		*/
		// Clear everything from the last frame
		window.clear();
		// Draw our game scene here
		// 
		window.draw(spriteBackground);

		window.draw(spriteTree);

		window.draw(spriteBee);

		window.draw(spriteCloud1);

		window.draw(spriteCloud2);

		window.draw(spriteCloud3);
		// 
		// Show everything we just drew
		window.display();
	}
	return 0;
}