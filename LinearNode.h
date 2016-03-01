/*
 * Ricardo Rigodon
 * LinearNode.h
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#ifndef LINEARNODE_H
#define LINEARNODE_H

template <class T>
struct linearNode
{
	//the element in the queue
	T info;
	//holds reference to next element in the queue
	struct linearNode *next;
};

#endif
