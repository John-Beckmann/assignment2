// John Beckmann created this.

#include "Skateboard.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Skateboard::Skateboard(string brand, string model, int gearCount)
{
	srand(time(0));
    setBrand(brand);
    setModel(model);
}

Skateboard::~Skateboard() = default;

double Skateboard::mileageEstimate(double time)
{
	// time input is given in minutes.
	
	// Generate a random number for miles per minute between 0.1 and 0.5 up to 3 digits.
	double mpm = float((rand())%401 + 100) / 1000.0;
	
	// Compute mileage. Speed times time. 
	double mileage = mpm*time;
	
	if(time > 25 && time < 250)
	{
		// Add extra mileage.
		int athird = time / 3.0;
		athird += 1;
		mileage += rand()%athird + 1;
	}
	
    return mileage;
}

string Skateboard::toString()
{
    return "-> Skateboard\n" + Vehicle::toString();
}