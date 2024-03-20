#include "Shield.h"

//Method to initialize the shield texture
void Shield::initTexture() {
	if (!texture.loadFromFile("Textures/shield.png")) {
		std::cout << "Error loading shield texture";
	}
}

//Method to initialize the shield sprite
void Shield::initSprite(int xPosition, int yPosition) {
	sprite.setTexture(this->texture);
	sprite.scale(4.0f, 4.0f);
	sprite.setPosition(xPosition, yPosition);
}

void Shield::initVertices() {
	vertices = sf::VertexArray(sf::Lines, 8);
	//Top horizontal line
	vertices[0].position = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y);
	vertices[1].position = sf::Vector2f(sprite.getPosition().x + 80, sprite.getPosition().y);
	//Bottom horizontal line
	vertices[2].position = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 60);
	vertices[3].position = sf::Vector2f(sprite.getPosition().x + 80, sprite.getPosition().y + 60);
	//Left vertical line
	vertices[4].position = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y);
	vertices[5].position = sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + 60);
	//Right vertical line
	vertices[6].position = sf::Vector2f(sprite.getPosition().x + 80, sprite.getPosition().y);
	vertices[7].position = sf::Vector2f(sprite.getPosition().x + 80, sprite.getPosition().y + 60);
}

//Constructor
Shield::Shield(int xPosition, int yPosition) {
	health = 20;
	damageToTake = 2;
	initTexture();
	initSprite(xPosition, yPosition);
	initVertices();
}

//Destructor
Shield::~Shield() {
}

//Method to get shield vertices (hitbox)
sf::VertexArray Shield::getVertices() {
	return vertices;
}

//Method to get current shield health
int Shield::getHealth() {
	return health;
}

//Method to take damage
void Shield::TakeDamage() {
	health -= damageToTake;
}

//Method to render shield to the screen
void Shield::render(sf::RenderTarget& target) {
	target.draw(sprite);
}