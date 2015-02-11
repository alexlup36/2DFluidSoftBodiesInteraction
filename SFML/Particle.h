#ifndef PARTICLE_H
#define PARTICLE_H

#include "Common.h"

class Particle
{
public:
	Particle(const sf::Vector2f& position, float radius);
	~Particle();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	// Getters and setters
	inline void SetPosition(const sf::Vector2f& newPosition) { m_Position = newPosition; }
	inline const sf::Vector2f GetPosition() const { return m_Position; }

	inline void SetPredictedPosition(const sf::Vector2f& newPredPos) { m_PredictedPosition = newPredPos; }
	inline const sf::Vector2f GetPredictedPosition() const { return m_PredictedPosition; }
	
	inline void SetVelocity(const sf::Vector2f& newVelocity) { m_Velocity = newVelocity; }
	inline sf::Vector2f GetVelocity() const { return m_Velocity; }

	inline void SetForce(const sf::Vector2f& newForce) { m_Force = newForce; }
	inline sf::Vector2f GetForce() const { m_Force; }

	inline float GetRadius() const { return m_fRadius; }

	inline bool IsAtLimit()
	{
		m_bLeft = m_Position.x <= PARTICLE_LEFTLIMIT;
		m_bRight = m_Position.x >= PARTICLE_RIGHTLIMIT;
		m_bTop = m_Position.y >= PARTICLE_BOTTOMLIMIT;
		m_bBottom = m_Position.y <= PARTICLE_TOPLIMIT;

		return m_bLeft || m_bRight || m_bTop || m_bBottom;
	}

	inline bool IsCollision(const Particle& other)
	{
		float radiusSum = other.GetRadius() + m_fRadius;
		float fDx = m_Position.x - other.GetPosition().x;
		float fDy = m_Position.y - other.GetPosition().y;

		return radiusSum * radiusSum > (fDx * fDx) + (fDy * fDy);
	}

	inline void SetIsColliding() { m_Shape.setFillColor(sf::Color::Red); }
	inline void SetAsNeighbor() { m_Shape.setFillColor(sf::Color::Magenta); }

	inline int GetParticleIndex() const { return m_iParticleIndex; }

	inline float GetParticleMass() const { return m_fMass; }

private:
	// Limits
	bool m_bLeft;
	bool m_bRight;
	bool m_bTop;
	bool m_bBottom;

	static int m_iGlobalIndex;
	int m_iParticleIndex;

	sf::CircleShape m_Shape;
	float m_fRadius;

	sf::Vector2f m_Position;
	sf::Vector2f m_PredictedPosition;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Force;
	float m_fMass;
	float m_fInvMass;

	void UpdateExternalForces(float dt);
	void DampVelocity();
	void CalculatePredictedPosition(float dt);
	void UpdateActualPosAndVelocity();
};

#endif // PARTICLE_H