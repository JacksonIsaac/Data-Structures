// Queue Data Structure for integer data type.
// Queue_Int.h
// Author: Jackson Isaac
// Date: 23 March, 2014
// Time: 21:55

#ifndef QUEUE_INT_INCLUDED
#define QUEUE_INT_INCLUDED

#include<iostream>
#include<cstdlib>
#include<stdexcept>

using namespace std;

class Queue_Int
{
public:
    typedef size_t size_type;
    typedef int data_type;
private:
    static const size_type max_queue_size = 5;
    data_type data[max_queue_size];
    data_type queue_size;
    int front_queue;        // Front pointer
    int rear_queue;         // Rear pointer

public:
    Queue_Int(): queue_size(0), front_queue(-1), rear_queue(-1)
    {
        for(size_t i = 0; i < max_queue_size;i++)
            data[i] = 0;
    }

    /* Check if the Queue is empty */
    bool empty() const    {    return (queue_size == 0);    }

    /* Insert element at position pointed by rear */
    void push(const int& x);

    /* Pop the element pointed by front_queue */
    void pop();

    /* Return the size of the queue */
    size_type size() const    			{    return queue_size;    }

    /* Get the data pointed by front and rear */
    data_type& front()					{	return data[front_queue];			}
    const data_type& front() const		{	return data[front_queue];	}

    data_type& rear()					{	return data[rear_queue];			}
    const data_type& rear() const		{	return data[rear_queue];		}

    /* Print the queue */
    void print(ostream& out = cout);// const;

    friend ostream& operator << (ostream& out, const Queue_Int& x);
};
#endif // QUEUE_INT_INCLUDED
