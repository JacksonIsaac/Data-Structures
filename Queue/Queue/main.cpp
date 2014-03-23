// Queue Data Structure for integer data type.
// Author: Jackson Isaac
// Date: 23 March, 2014
// Time: 21:55

#include <iostream>
#include <string>
#include "Queue_Int.h"

using namespace std;

int main()
{
    Queue_Int q;
    string in;
    int data;
    while(true)
	{
		cin >> in;
		try {
			if(in == "push")
			{
				cin>>data;
				q.push(data);
			}
			else if(in == "pop")	q.pop();
			else if(in == "print")	q.print();
			else if(in == "exit")	break;
			else if(in == "front")	q.front();
			else if(in == "rear")	q.rear();
			else					cerr << "Invalid Input" << endl;
		}
		catch (const overflow_error& e) { cerr << e.what() << endl; }
		catch (const underflow_error& e){ cerr << e.what() << endl; }
		
	}
	
	cout << q, cout<<endl;
	return EXIT_SUCCESS;
}
