/*
 * Ricardo Rigadon
 * LinkedQueue.cpp
 *
 * Instructor: Dr. DePasquale
 * Due Date: 5/8/2015
 *
 */

#include "LinkedQueue.h"
#include "LinearNode.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

//default constructor
template<class T>
LinkedQueue<T>::LinkedQueue()
{
	count = 0;
	front = NULL;
	rear = NULL;
}

//adds an element of any type to the queue
template <class T>
void LinkedQueue<T>::enqueue(T const& element)
{
	linearNode<T> *temp = new linearNode<T>();

	temp->info = element;
	temp->next = NULL;

	if(isEmpty())
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}
	rear = temp;
    count++;
}

//removes an element of any type from the queue
template <class T>
T LinkedQueue<T>::dequeue()
{
	linearNode<T> *temp;
	T result;
	//checks if the queue is empty and if so throws a logic error
	if(isEmpty())
	{
		throw std::logic_error("Nothing to dequeue");
	}
	else
	{
		temp = front;

        front = front->next;

        result = temp->info;

        delete temp;
	}

	if(count > 0)
	count--;

	return result;
}

//checks if the queue is empty
template <class T>
bool LinkedQueue<T>::isEmpty()
{
	return count==0;
}

