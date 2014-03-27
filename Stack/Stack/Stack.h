// Stack_Int Class definition
//Author: Jackson Isaac
//Class: S4 CSE A
//Roll No: U4CSE12021

#ifndef __STACK_H__
#define __STACK_H__

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<stdexcept>
#include<ostream>

using std::cout;
using std::endl;
using std::operator <<;
using std::size_t;
using std::ostream;

class Stack_Int
{
public:
	typedef size_t size_type;
	typedef signed int value_type;

private:
	/* Size of the Stack */
	static const size_type stack_size = 10;

	/* Array for holding data */
	value_type data[stack_size];

	/* Top of the Stack */
	value_type top_of_stack;

public:
	/* Default constructors */
	Stack_Int():top_of_stack(-1)
	{ }

	/* Member Functions */
	bool empty() const				{ return(top_of_stack == -1); }		/* Function to check whether the stack is empty */

	size_type size() const			{ return(top_of_stack + 1); }		/* Number of Elements in the Stack */

	/* Return the value at the top */
	value_type& top()				{ return data[top_of_stack]; }		/* Non-const version for non-const objects */
	const value_type& top() const	{ return data[top_of_stack]; }		/* Const version for const objects */

	void push(const value_type& x);										/* To insert data into the stack */
	
	void pop();															/* Removes the data from the top of the stack */

	friend ostream& operator << (ostream &, const Stack_Int &);			/* Overload output operator using friend function */ 

};

#endif