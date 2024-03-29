#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <cwchar>
#include <iostream>
#include <random>
#include "random_helper.h"


using std::sqrt;

class vec3 {
	public:
		vec3() : e{0,0,0} {}
		vec3(double e1,double e2,double e3) : e{e1,e2,e3} {}

		double e[3];

		double x() const { return e[0];}
		double y() const { return e[1];}
		double z() const { return e[2];}

		vec3 operator-() const{ 
			return vec3(-e[0],-e[1],-e[2]); 
		}

		double operator[] (int i) const {return e[i];}
		double operator&  (int i) {return e[i];}

		vec3& operator+=(const vec3 &v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];

			return *this;
		}

		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;

			return *this;
		}

		vec3& operator/=(double t) {
			return *this /= 1/t;
		}

		double length_squared(){
			return e[0]*e[0] +e[1]*e[1]+e[2]*e[2];
		}

		double length(){
			return sqrt(length_squared());
		}

		static vec3 random(){
			return vec3(random_double(),random_double(),random_double());
		}
		static vec3 random(double min,double max){
			return vec3(random_double(min,max),random_double(min,max),random_double(min,max));
		}
};


// define point3 to be vec3
using point3=vec3;
// Helper functions

template<typename T, typename U>
inline T operator+(const T &v1,const U &v2)
{
	return T(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]);
}


template<typename T>
inline T operator-(const T &v1,const T &v2){
	return v1+-v2;
}


template<typename T>
inline T operator*(const T &v,const double t)
{
	return T(v.e[0]*t,v.e[1]*t,v.e[2]*t);
}

template<typename T>
inline T operator*(const double t,const T &v)
{
	return v*t;
}


template<typename T>
inline T operator/(const T &v,const double t)
{
	return T(v.e[0]/t,v.e[1]/t,v.e[2]/t);
}

template<typename T>
inline T unit_vector(T v)
{
	return v/v.length();
}

template<typename T>
inline double dot(const T &a, const T &b )
{
	return a.e[0]*b.e[0] + a.e[1]*b.e[1] + a.e[2]*b.e[2];
}


inline vec3 random_in_unit_sphere()
{
	while(true){
		auto p = vec3::random(-1,1);
		if(p.length_squared()<1) // if the length is s
			return p;
	}
}

inline vec3 random_unit_vector()
{
	return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal)
{
	// simple hack to deterimine if the vec is pointing the same direction
	// as the normal ( ie being on the same hemisphere)
	//
	// 1) generate a random vector strictly within the unitsphere
	// 2) normalizze the vector
	// 3) if pointing the wring direction invert
	vec3 u_vect = random_unit_vector();
	if (dot(u_vect,normal) > 0.0) {
		return u_vect;
	}
	else {
		return -u_vect;
	}
}

#endif


