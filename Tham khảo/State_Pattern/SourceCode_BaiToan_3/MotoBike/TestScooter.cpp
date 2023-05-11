#include "Scooter.h"


int main()
{
	Scooter newBike;

	newBike.ToString();
	newBike.UseKey();
	newBike.StartButton();
	newBike.UseKey();
	newBike.UseKey();
	newBike.StartButton();
	newBike.ThrottleHandle();
	newBike.UseKey();
	newBike.Brake();
	newBike.ThrottleHandle();
	newBike.ThrottleHandle();
	newBike.Brake();
	newBike.UseKey();
	std::cout<<newBike.ToString();
}