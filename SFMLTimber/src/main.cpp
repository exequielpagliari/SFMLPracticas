// Include important libraries here
#include <SFML/Graphics.hpp>
// Make code easier to type with "using namespace"
using namespace sf;
// This is where our game starts from
int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
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

		//Creada Textura de Fondo
		Texture textureBackground;
		//Carga de Textutra de archivo
		textureBackground.loadFromFile("../graphics/background.png");
		//Creacción de Sprite
		Sprite spriteBackground;
		//Carga de Textura en el Sprite
		spriteBackground.setTexture(textureBackground);
		//Seteo de posición del Sprite
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
		// 
		// Show everything we just drew
		window.display();
	}
	return 0;
}