#pragma once

class Node
{
private:
	int data;
	Node* left;
	Node* right;

public:
	Node():left(NULL),right(NULL),data(0)		{ }

	Node(int d):left(NULL),right(NULL),data(d)	{ }
	
	void set_data(int d)			{ data = d;		}
	void set_left_ptr(Node* l)		{ left = l;		}
	void set_right_ptr(Node* r)		{ right = r;	}

	int get_data()			const	{ return data;	}
	Node* get_left_ptr()	const	{ return left;	}
	Node* get_right_ptr()	const	{ return right;	}
};