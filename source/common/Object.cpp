//////////////////////////////////////////////////////////////////////////////
//
//  --- Object.cpp ---
//  Created by Brian Summa
//
//////////////////////////////////////////////////////////////////////////////


#include "common.h"

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
Object::IntersectionValues Sphere::intersect(vec4 p0, vec4 V){
	IntersectionValues result;
	result.t = raySphereIntersection(p0, V);
	result.P = p0;
	result.N = V;
	return result;
}

/* -------------------------------------------------------------------------- */
/* ------ Ray = p0 + t*V  sphere at origin center and radius radius : Find t  */
double Sphere::raySphereIntersection(vec4 p0, vec4 V){
	// t²V*V + 2tV(p0-this.centre) + ||p0-this.centre||² - this.radius
	vec3 p0c = cross(p0, this->center);
	double a = dot(V, V);
	double b = 2*dot(V, p0c);
	double c = dot(p0c, p0c) - this->radius*this->radius;
	double delta = b*b - 4*a*c;
	if (delta > 0) {
		return a >= 0 ? (-b+sqrt(delta))/2*a : (-b-sqrt(delta))/2*a;
	} else if (delta == 0) {
		return -b/2*a;
	} else {
		return std::numeric_limits<double>::infinity();
	}
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
Object::IntersectionValues Square::intersect(vec4 p0, vec4 V){
  IntersectionValues result;
  //TODO: Ray-square setup
  
  return result;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
double Square::raySquareIntersection(vec4 p0, vec4 V){
  double t   = std::numeric_limits< double >::infinity();
  //TODO: Ray-square intersection;
  return t;
}
