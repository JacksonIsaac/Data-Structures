// Queue Data Structure for integer data type.
// Queue_Int.cpp
// Author: Jackson Isaac
// Date: 23 March, 2014
// Time: 21:55

#include "Queue_Int.h"

void Queue_Int::push(const int& x)
{
	/* Queue is full */
    if(((front_queue == 0) && (rear_queue == max_queue_size - 1))
       || (front_queue == rear_queue + 1))
    {
        throw overflow_error("Queue is full \n");
    }
    /* Queue is not full */
    else
	{
		/* Queue is empty */
		if(empty())
		{
			front_queue = rear_queue = 0;
			data[rear_queue] = x;
		}
		/* Queue has some elements */
		else
		{
			rear_queue = ((rear_queue == max_queue_size - 1) ? 0 : rear_queue + 1);
			data[rear_queue] = x;
		}
		queue_size++;
	}/* Queue not full */
}/* void push */

void Queue_Int::pop()
{
	if(empty())		throw underflow_error("Queue is Empty.");
	else
	{
		if(queue_size == 1)
		{
			data[front_queue] = 0;
			front_queue = rear_queue = -1;
		}
		else
		{
			data[front_queue] = 0;
			front_queue = ((front_queue == max_queue_size - 1) ? 0 : front_queue + 1);
		}
		queue_size--;
	}
}

void Queue_Int::print(ostream& out) //const
{
	if(empty())	cerr << "Queue is Empty" << endl;
	int temp = front_queue;
	while(!empty())
	{
		if(temp == rear_queue)
		{
			out<<"| "<<data[temp] << " |";
			break;
		}
		out<<"| "<<data[temp] << " |";
		temp++;
	}
	out << endl;
}

ostream& operator << (ostream& out, const Queue_Int& x)
{
	if(x.empty())	cerr << "Queue is Empty" << endl;
	int temp = x.front_queue;
	while(!x.empty())
	{
		if(temp == x.rear_queue)
		{
			out<<"| "<<x.data[temp] << " |";
			break;
		}
		out<<"| "<<x.data[temp] << " |";
		temp++;
	}
	out << endl;
	return out;
}
