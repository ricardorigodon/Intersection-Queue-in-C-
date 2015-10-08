/*
 * Ricardo Rigadon
 * LinkedQueue.h
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "LinearNode.h"

template <class T>
class LinkedQueue
{

	private:
		//counts the number of elements in the queue
		int count;
		//holds reference to the front of the queue
		linearNode<T> *front;
		//holds reference to the end of the queue
		linearNode<T> *rear;

	public:
		//constructor
		LinkedQueue();
		//adds an element to the queue
		void enqueue(T const& element);
		//removes an element from the queue
		T dequeue();
		//checks if the queue is empty
		bool isEmpty();
};

#endif
