#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Shield {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int health;
	int damageToTake; //How much damage a bullet deals to the shield
	sf::VertexArray vertices;
	//Initialize variables
	void initTexture();
	void initSprite(int xPosition, int yPosition);
	void initVertices();
public:
	Shield(int xPosition, int yPosition);
	~Shield();

	//Method to get vertices (hitbox)
	sf::VertexArray getVertices();

	//Method to get health and take damage
	int getHealth();
	void TakeDamage();

	//Method to render shield to window
	void render(sf::RenderTarget& target);
};