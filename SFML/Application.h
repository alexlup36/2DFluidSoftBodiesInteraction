#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>

#include "Common.h"
#include "Particle.h"
#include "SpatialPartition.h"

class Application
{
public:
	Application();
	~Application();

	void Initialize();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void BuildParticleSystem(int iParticleCount);

	sf::Vector2f GetRandomPosWithinLimits(float fRadius);

private:
	sf::Texture m_Texture;

	std::vector<Particle> m_ParticleList;

	SpatialPartition m_SpatialManager;

	inline float Dot(const sf::Vector2f& v1, const sf::Vector2f& v2) { return v1.x * v2.x + v1.y * v2.y; }
	inline void PrintVector2(const sf::Vector2f& v) { std::cout << "x = " << v.x << " y = " << v.y << std::endl; }
};



#endif // APPLICATION_H