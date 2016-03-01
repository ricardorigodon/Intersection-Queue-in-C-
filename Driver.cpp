/*
 * Ricardo Rigodon
 * Driver.cpp
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

using namespace std;
#include "Processor.h"
#include <iostream>
#include <stdio.h>
#include <fstream>



int main()
{
	//creates a txt file and writes outputs to it
	ofstream write;
	write.open("output.txt");

	//creates a Processor object
	Processor process;
	//calls the traffic method of the proessor object
	process.Traffic(write);

	return 0;

}
