/* Main function definition */
#include"Stack.h"

using namespace std;

int main()
{
	Stack_Int st;
	string op;
	int data;

	while(1)
	{
		try
		{
			cin >> op;
			if (op == "push")
			{
				cin >> data;
				st.push(data);
			}
			else if (op == "pop") st.pop();
			else if (op == "print") cout << st << endl;
			else if (op == "exit") break;
			else cerr << "Wrong Command" << endl;
		}
		catch(const overflow_error& e)
		{
			cerr << e.what() << endl;
		}
		catch(const underflow_error& e)
		{
			cerr << e.what() << endl;
		}
	}
	return 0;
}
