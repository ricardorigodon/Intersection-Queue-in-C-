/*
 * Ricardo Rigadon
 * Processor.cpp
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#include "Vehicle.h"
#include "Processor.h"
#include "LinkedQueue.h"
#include "LinkedQueue.cpp"
#include <stdlib.h> //random
#include <iostream>
#include <fstream>
#include <ctime> //to reset random seed so not the same number is generated every time
using namespace std;

Processor::Processor()
{
	carTime = 0;
	vNum = 1;
	vCount = 0;
}


LinkedQueue<Vehicle> intersection[6]; //Making array of queues to add vehicles in

//creates vehicles and places them in queues
void Processor::createVehicles(int min, int max)
{
	srand(time(NULL));
	int count = rand()%(max-min)+min; //how many vehicles will be created
	
	
	
	//depending on the random number the vehicle is put in a queue
	for(int i = 0 ; i < count; i++)
	{
		lanes = rand() % 6;
		if(vCount < 120)
		{
		//sets the road and direction 
		switch(lanes)
		{
			case 0 : tempRoad = Church;
				tempDirect = W;
				break;
			case 1 : tempRoad = Church;
				tempDirect = E;
				break;
			case 2 : tempRoad = Main;
				tempDirect = N;
				break;
			case 3 : tempRoad = Main;
				tempDirect = W;
				break;
			case 4 : tempRoad = Main;
				tempDirect = N;
				break;
			case 5 : tempRoad = Main;
				tempDirect = E;
				break;


		}
		//creates the vehicle object
		Vehicle v(vNum , tempRoad, tempDirect, carTime);
		//increments vehicleNumber and count
 		vNum++;
		vCount++;
		//puts the vehicle in its apporopriate queue
		intersection[lanes].enqueue(v);
	}


	}

	



}

//provides simulation of the intersection
void Processor::Traffic(ofstream& write)
{

	
	//only 7 to 12 vehicles once for the beginning
	if(vCount == 0)
	{
		createVehicles(7,12);
    }
	//used to stpre object returned by dequeue
    Vehicle car;
	
	//used to store the total time minus the arrival time
    int vTime = 0;
	//used in the following loop
    int churchTime = carTime + 6;

    write<< "-----------Processing Church Street Traffic-------------"<<endl;

	//if intersection is not empty dequeues, stores in car variable and outputs to output.txt
    while(carTime != churchTime)
    {
    	if(!intersection[0].isEmpty())
    	{
    		car = intersection[0].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
            write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(southbound) turned left and headed westbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}

    	if(!intersection[1].isEmpty())
    	{
    		car = intersection[1].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
             write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(southbound) turned right and headed eastbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}
		//increments car time
    	carTime = carTime + 3;
    }
	//creates 8 to 15 vehicles if the vehicle count is less than 120
    if(vCount < 120)
    {
    	createVehicles(8,15);
    }

	//creates a variable that is nine more than the current time
    int mainTime = carTime + 9;

    write<<"----------Processing Main Street Traffic------------"<<endl;
	
	//if intersection is not empty dequeues, stores in car variable and outputs to output.txt
    while(carTime != mainTime)
    {
    	if(!intersection[2].isEmpty())
    	{
    		car = intersection[2].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
            write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(westbound) turned right and headed northbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}

    	if(!intersection[3].isEmpty())
    	{
    		car = intersection[3].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
            write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(westbound) continued straight and continued westbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}

    	if(!intersection[4].isEmpty())
    	{
    		car = intersection[4].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
            write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(eastbound) turned left and headed northbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}

    	if(!intersection[5].isEmpty())
    	{
    		car = intersection[5].dequeue();
    		car.setDepartureTime(carTime);
    		vTime = carTime - car.getArrivalTime();
            write<<"[Time "<< carTime << "]" << " Vehicle  #" <<car.getVehicleNumber() << "(eastbound) continued straight and headed eastbound." << "Total wait time " << vTime << " seconds"<<endl;

    	}
		//increments car time variable
    	carTime = carTime + 3;
    }

	//creates 3 to 15 vehicles as long as vehicle count is less than 120
    if(vCount < 120)
    {
    	createVehicles(3,15);
    }

	//checks if at least one of the queues has a vehicle; traffic will call itself recursively until all vehicles have been dequeued
    if(!intersection[0].isEmpty() || !intersection[1].isEmpty() || !intersection[2].isEmpty() || !intersection[3].isEmpty() || !intersection[4].isEmpty() || !intersection[5].isEmpty() )
        {
            Traffic(write);
        }
	write.close();
}


