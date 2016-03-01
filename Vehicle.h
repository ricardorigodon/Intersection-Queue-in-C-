/*
 * Ricardo Rigodon
 * Vehicle.h
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */
 
#ifndef VEHICLE_H  
#define VEHICLE_H



#include "Street.h"
#include "Direction.h"


class Vehicle
{
   private:
	//The vehicle count
   	int vehicleNumber;
	//Time the vehicle is added to the queue
   	int arrivalTime;
	//Time the vehicle leaves the queue
   	int departureTime;
	//enum for the street 
   	street road;
	//enum for the direction
   	direction direct; 

   public:
	//Vehicle constructor
   	Vehicle(int, street, direction, int);
	//Default vehicle constructor
    Vehicle();
	//sets the vehicleNumber
   	void setVehicleNumber(int);
	//returns the vehicleNumber
   	int getVehicleNumber();
	//sets the arrivalTime
    void setArrivalTime(int);
	//returns the arrivalTime
    int getArrivalTime();
	//sets the departureTime
    void setDepartureTime(int);
	//returns the departureTime
    int getDepartureTime();
	//sets the direction
   	void setDirection(direction);
	//returns the direction
    direction getDirection();
	//sets the street
    void setStreet(street);
	//returns the street
    street getStreet();
	//outputs the info of vehicles
    void toString();



};

#endif
