// John Beckmann created this.

#include "Jet.h"
#include <cstdlib>
#include <ctime>


Jet::Jet()
{
	srand(time(0));
    numberOfEngines = 1;
    setBrand("unknown");
    setModel("unknown");
}

Jet::Jet(string brand, string model, string fuelType, int numEngines)
{
	srand(time(0));
    setBrand(brand);
    setModel(model);
    setFuelType(fuelType);
    setNumEngines(numEngines);
}

Jet::~Jet() = default;

int Jet::getNumEngines()
{
    return numberOfEngines;
}

void Jet::setNumEngines(int numEngines)
{
    if (numEngines >= 1)
        numberOfEngines = numEngines;
	else
        // Users cant not specify that a Jet has less than one engine.
		numberOfEngines = 1;
}

double Jet::mileageEstimate(double time)
{
	// time is given in minutes.
    // Random number generator generates a number between 40 and 100 that represents the miles per minute of the Jet.
	double mileage = time*(rand()%61 + 40);
	
	// The total mileage goes up 5.5% for every engine it has after 2 engines.
    if (fuelType == "Rocket" && numberOfEngines > 2)
	{
        mileage += mileage * (0.055 * numberOfEngines);
    }
    return mileage;
}

string Jet::toString()
{
    return "-> Jet\n" + PoweredVehicle::toString() + "\n\tNumber of Engines: " + to_string(numberOfEngines);
}