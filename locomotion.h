#ifndef LOCOMOTION_H
#define LOCOMOTION_H

#include "wheel.h"


class Locomotion
{
	private:
		Wheel left_wheel;
		Wheel right_wheel;

		Locomotion();
	public:
    	static Locomotion& get();
};

#endif
