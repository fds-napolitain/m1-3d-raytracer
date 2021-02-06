//////////////////////////////////////////////////////////////////////////////
//
//  --- Object.cpp ---
//  Created by Brian Summa
//
//////////////////////////////////////////////////////////////////////////////


#include "common.h"

// cast
vec3 toVec3(vec4 v) {
	return vec3(v.x, v.y, v.z);
}

vec4 toVec4(vec3 v) {
	return vec4(v.x, v.y, v.z, 0);
}

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
	vec3 p03 = toVec3(p0); // why the hell vec4?
	vec3 V3 = toVec3(V);
	// t²V*V + 2tV(p0-this.centre) + ||p0-this.centre||² - this.radius
	double a = dot(V3, V3);
	double b = 2.0*dot(V3, p03-this->center);
	double c = dot(p03-this->center, p03-this->center) - this->radius*this->radius;
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
  result.t = raySquareIntersection(p0, V);
  result.N = V;
  result.P = p0 + result.t * V;
  return result;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
double Square::raySquareIntersection(vec4 p0, vec4 V){
	vec3 po3 = toVec3(p0);
	vec3 V3 = toVec3(V);
	vec3 point3 = toVec3(this->point);
	// (D - on) / (dn) avec D = an
	double denominateur = dot(point3, this->normal) - dot(po3, this->normal);
	double numerateur = dot(V3, this->normal);
	if (numerateur != 0 && denominateur / numerateur > 0) {
		return denominateur / numerateur;
	}
	return std::numeric_limits<double>::infinity();
}
