#ifndef __ITERATOR_NODE_H__
#define __ITERATOR_NODE_H__


#include "Node.h"
using std::cout;
using std::endl;

class Iterator_Node
{
private:
	Node *node_ptr;
public:
	Iterator_Node(Node *p):node_ptr(p)	{ }

	Node *get_node_ptr()	{ return node_ptr; }

	/* Overload indirection operator		*/
	int& operator*()
	{
		assert(node_ptr != NULL);
		return node_ptr->data;
	}

	const int& operator*() const
	{
		assert(node_ptr != NULL);
		return node_ptr->data;
	}

	/* Overload arrow operator				*/
	int* operator->()
	{
		assert(node_ptr != NULL);
		return &(node_ptr->data);
	}

	const int* operator->() const
	{
		assert(node_ptr != NULL);
		return &(node_ptr->data);
	}

	/* Overload equality operators			*/
	bool operator == (const Iterator_Node &i)	
	{ 
		return (this->node_ptr == i.node_ptr); 
	}

	bool operator != (const Iterator_Node &i)	
	{ 
		return !(*this == i); 
	}

	/* Overload postfix and prefix operator	*/
	Node& operator++ ()								/* Prefix	*/
	{
		node_ptr = node_ptr->get_next_ptr();
		return (*node_ptr);
	}

	Node operator++ (int)							/* Postfix	*/
	{
		Node *temp = this->node_ptr;
		node_ptr = node_ptr->get_next_ptr();
		return (*temp);
	}

};

#endif