/*
 * Ricardo Rigadon
 * Vehicle.cpp
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#include "Vehicle.h"
#include "Street.h"
#include "Direction.h"
#include <iostream>

using namespace std;

	//Default constructor
	Vehicle::Vehicle()
	{

	}

	//constructor
	Vehicle::Vehicle(int vNum, street b , direction a, int aTime)
	{
		vehicleNumber = vNum;
		arrivalTime = aTime;
		road = b;
		direct = a;

	}
	//Sets the vehicleNumber
	void Vehicle::setVehicleNumber(int num)
	{
		vehicleNumber = num;
	}
	//returns the vehicleNumber
	int Vehicle::getVehicleNumber()
	{
		return vehicleNumber;
	}
	//sets the arrivalTime
	void Vehicle::setArrivalTime(int num)
	{
		arrivalTime = num;
	}
	//returns the arrivalTime
	int Vehicle::getArrivalTime()
	{
		return arrivalTime;
	}
	//sets the departureTime
	void Vehicle::setDepartureTime(int num)
	{
		departureTime = num;
	}
	//returns the departureTime
	int Vehicle::getDepartureTime()
	{
		return departureTime;
	}
	//seets the direction
	void Vehicle::setDirection(direction c)
	{
        direct = c;
	}
	//returns the direction
	direction Vehicle::getDirection()
	{
		return direct;
	}
	//sets the street
	void Vehicle::setStreet(street d)
	{
		road = d;
	}
	//returns the street
	street Vehicle::getStreet()
	{
		return road;
	}
	//outputs the info of the vehicle
	void Vehicle::toString()
	{
		cout<< vehicleNumber << "  " <<  road << "  " << direct << "  " << arrivalTime << endl;
	}




