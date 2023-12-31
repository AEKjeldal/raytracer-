#ifndef  INTERVAL_H
#define  INTERVAL_H


#include "common.h"
class interval
{

	public:
		double min,max;
		interval() : min(+infinity), max(-infinity) {}
		interval(double _min,double _max) : min(_min), max(_max) {}

		bool contains(double x) const {
			return min <= x && x <= max;
		}
		bool surrounds(double x) const {
			return min < x && x < max;
		}

		// limit x to be within interval
		double clamp(double x) {
			if (x < min) return min;
			if (x > max) return max;
			return x;
		}

		static const interval empty, universe;

};

const static interval empty(+infinity,-infinity);
const static interval universe(-infinity,+infinity);


#endif // ! INTERVAL_H
