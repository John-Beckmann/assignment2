// John Beckmann created this.

#ifndef DRIVINGSIMULATOR_TRAIN_H
#define DRIVINGSIMULATOR_TRAIN_H

#include "PoweredVehicle.h"

class Train : public PoweredVehicle
{

	private:
		string cargo;
		bool isMagic;

	public:
		Train();

		explicit Train(string brand, string model, string fuelType, string contents, bool magical);

		virtual ~Train();
		string getCargoType();
		void setCargoType(string contents);
		bool getMagicness();
		void setMagicness(bool magical);
		virtual double mileageEstimate(double time);
		virtual string toString();
};

#endif