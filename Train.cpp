// John Beckmann created this.

#include "Train.h"
#include <cstdlib>
#include <ctime>

Train::Train()
{
	srand(time(0));
    setBrand("unknown");
    setModel("unknown");
	setFuelType("unknown");
	setCargoType("unknown");	
	setMagicness(false);
}

Train::Train(string brand, string model, string fuelType, string contents, bool magical)
{
	srand(time(0));
    setBrand(brand);
    setModel(model);
    setFuelType(fuelType);
    setCargoType(contents);
	setMagicness(magical);
}

Train::~Train() = default;

string Train::getCargoType()
{
	return cargo;
}

void Train::setCargoType(string contents)
{
	if(contents == "freight" || contents == "passenger" || contents == "unknown")
		cargo = contents;
	else
		cargo = "unknown";
}

bool Train::getMagicness()
{
	return isMagic;
}

void Train::setMagicness(bool magical)
{
	isMagic = magical;	
}

double Train::mileageEstimate(double time)
{
	double mileage = 0;
	
	/* if a train is a passenger train its speed in miles per minute is a random number between    */
	if(cargo == "passenger")
		mileage = time*(rand()%61 + 60);
	else if(cargo == "freight")
		mileage = time*(rand()%41 + 30);
	else
		mileage = time*30;
	
    return mileage;
}

string Train::toString()
{
	string magic_string;
	
	if(getMagicness())
		magic_string = "Yes, magic as hell\n";
	else
		magic_string = "Nah, not magic at all\n";
	
    return "-> Train\n" + PoweredVehicle::toString() + "\n\tCargo Type: " + getCargoType()	+ "\n\tMagic? " + magic_string;
}