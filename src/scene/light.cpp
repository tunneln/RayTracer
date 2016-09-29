#include <cmath>

#include "light.h"
#include <glm/glm.hpp>


using namespace std;

double DirectionalLight::distanceAttenuation(const glm::dvec3& P) const
{
	// distance to light is infinite, so f(di) goes to 0.  Return 1.
	return 1.0;
}


glm::dvec3 DirectionalLight::shadowAttenuation(const ray& r, const glm::dvec3& p) const
{
	ray l_r = r;
    isect i;

    if (scene->intersect(l_r, i)) 
        return glm::dvec3(0.0, 0.0, 0.0);

	return glm::dvec3(1.0, 1.0, 1.0);
}

glm::dvec3 DirectionalLight::getColor() const
{
	return color;
}

glm::dvec3 DirectionalLight::getDirection(const glm::dvec3& P) const
{
	return -orientation;
}

double PointLight::distanceAttenuation(const glm::dvec3& P) const
{

	// YOUR CODE HERE

	// You'll need to modify this method to attenuate the intensity 
	// of the light based on the distance between the source and the 
	// point P.  For now, we assume no attenuation and just return 1.0
	return 1.0;
}

glm::dvec3 PointLight::getColor() const
{
	return color;
}

glm::dvec3 PointLight::getDirection(const glm::dvec3& P) const
{
	return glm::normalize(position - P);
}

glm::dvec3 PointLight::shadowAttenuation(const ray& r, const glm::dvec3& p) const
{
	ray l_r = r;
    isect i;

    if (scene->intersect(l_r, i) && i.t < glm::length(this->position - p))
        return glm::dvec3(0.0, 0.0, 0.0);

	return glm::dvec3(1.0, 1.0, 1.0);
}

