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
	result.N = V;
	result.P = p0 + result.t * V;
	return result;
}

/* -------------------------------------------------------------------------- */
/* ------ Ray = p0 + t*V  sphere at origin center and radius radius : Find t  */
double Sphere::raySphereIntersection(vec4 p0, vec4 V){
	// t²V*V + 2tV(p0-this.centre) + ||p0-this.centre||² - this.radius
	double a = dot(V, V);
	double b = 2*dot(V, p0-this->center);
	double c = dot(p0-this->center, p0-this->center) - this->radius*this->radius;
	double delta = b*b - 4*a*c;
	if (delta > 0) {
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);
		if (t1 < t2 && t1 > 0) {
			return t1;
		} else if (t2 < t1 && t2 > 0) {
			return t2;
		}
		return std::numeric_limits<double>::infinity();
	} else if (delta == 0) {
		return (-b)/(2*a);
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
