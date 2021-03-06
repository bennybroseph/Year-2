#ifndef _PLANET_H_
#define _PLANET_H_
#pragma once

#include "Transform.h"

class Planet;

typedef unique_ptr<Planet> PlanetPtrU;
typedef shared_ptr<Planet> PlanetPtrS;
typedef weak_ptr<Planet> PlanetPtrW;


class Planet
{
public:

	/// <summary>
	/// The preferred way to construct a Planet object
	/// </summary>
	/// <param name="position">The initial position of the planet</param>
	/// <param name="radius">The initial radius of the sphere when drawn</param>
	/// <param name="colour">The initial color of the sphere when drawn</param>
	/// <param name="speed">The initial rotation speed of the planet</param>
	Planet(const vec3 &position, float radius, const vec4 &colour, float speed);

	void update(const float &deltaTime) const;

	/// <summary>
	/// Returns a modifiable reference to the 'm_transform' variable
	/// </summary>
	/// <returns>Modifiable reference to the 'm_transform' variable</returns>
	Transform& transform();

	/// <summary>
	/// Returns a modifiable reference to the 'm_radius' variable
	/// </summary>
	/// <returns>Modifiable reference to the 'm_radius' variable</returns>
	float& radius();
	/// <summary>
	/// Returns a modifiable reference to the 'm_colour' variable
	/// </summary>
	/// <returns>Modifiable reference to the 'm_colour' variable</returns>
	vec4& colour();

	~Planet();

private:

	// The planet's transform variable
	const TransformPtrU m_transform = make_unique<Transform>();

	// Radius of the sphere when drawn
	float m_radius = 1.f;
	// Color of the sphere when drawn
	const vec4PtrU m_colour = make_unique<vec4>(0, 0, 0, 1);

	// Rotation speed of the planet
	float m_speed = 0.1f;
};

#endif // _PLANET_H_