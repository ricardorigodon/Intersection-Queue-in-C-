/*
 * Ricardo Rigadon
 * Processor.h
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <fstream>
#include "Vehicle.h"
#include "Street.h"
#include "Direction.h"
#include "LinkedQueue.h"
using namespace std;



class Processor
{
	private:
	//number of cars created
	int vCount;
	//the amount of time the car takes to move
	int carTime;
	//holds a temporary direction
	direction tempDirect;
	//holds a temporary street
	street tempRoad;
	//What queue its going in
	int lanes; 
	// number of vehicle
	int vNum; 

	public:
	//class constructor
	Processor();
	//creates the queues
	void createQueues();
	//creates the vehicles
	void createVehicles(int, int);
	//runs through the simulation
	void Traffic(ofstream&);


};

#endif
