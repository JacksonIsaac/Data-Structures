#include"Tree_Int.h"

#include<iostream>

using namespace std;

int main(){
	Tree_Int t;
	string in;
    int data;
    while(true)
	{
		cin >> in;
		try
		{
			if(in == "insert")
			{
				cin>>data;
				t.insert(data);
			}
			else if(in == "delete")
			{
				cin>>data;
				t.delete_node(data);
			}
			else if(in == "inorder")	t.inorder();
			else if(in == "postorder")	t.postorder();
			else if(in == "preorder")	t.preorder();
			else if(in == "levelorder")	t.levelorder();
			else if(in == "clear")		t.clear();
			else if(in == "exit")		break;
			else						cerr << "Invalid Input" << endl;
		}
		catch (const overflow_error& e) { cerr << e.what() << endl; }
		catch (const underflow_error& e){ cerr << e.what() << endl; }		
	}
	
	t.clear();

	return 0;
}