#include"Stack.h"

/* Insertion operator Overloaded */ 
ostream& operator << (ostream& out, const Stack_Int& s)
{
	if(s.size() > 0)
	{
		Stack_Int::size_type i = s.size() - 1;
		while (i != -1)
		{
			
			out << "+------+" << endl;
			out << "|"		  << std::setw(6)
				<< s.data[i]  << "|"
				<< ((i == s.size() -1)? "<-- Top" : "") <<endl;
			i--;
		}
		cout << "+------+" << endl;
	}
	else			  cout << "Stack Empty" <<endl;
	return out;
}

void Stack_Int::push(const value_type& x)
{
	if(top_of_stack == stack_size-1)
		throw std::overflow_error("Stack Overflow");
	data[++top_of_stack] = x;
	return;
}

void Stack_Int::pop()
{
	if(top_of_stack == -1)
		throw std::underflow_error("Stack Underflow");
	--top_of_stack;
	return;
}