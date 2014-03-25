#ifndef __TREE_INT_H__
#define __TREE_INT_H__

#include<iostream>
#include"Node.h"
#include <string>
#include<queue>
#include<cassert>

using namespace std;

struct print_type;

class Tree_Int
{
private:
	Node* root;
	size_t tree_size;
public:
	/* Constructor	*/
	Tree_Int():root(NULL),tree_size(0)	{ }

	/* Destructor	*/
	virtual ~Tree_Int()					{ clear(); }

	/* Insert element into the tree */
	void insert(const int& x)
	{
		if(root == NULL)
		{
			root = new Node(x);
			tree_size++;
		}
		else
			insertHelper(root,x);
	}

	void insertHelper(Node* node, int value);

	/* Clear the complete tree */
	void clear();
	void clear(Node*node);

	/* Getter function for root */
	Node* get_root()	const	{	return root;				}
	int get_data()		const	{	return root->get_data();	}

	/* Return the size of the tree */
	size_t size() const			{	return tree_size;			}

	/* Check if the tree is empty */
	bool empty()				{	return (tree_size == 0);	}

	/* Traversing functions */
	void inorder (Node* node, ostream& out = cout);
	void inorder (ostream& out = cout);
	void postorder(Node* node, ostream& out = cout);
	void postorder (ostream& out = cout);
	void preorder(Node* node, ostream& out = cout);
	void preorder (ostream& out = cout);
	void levelorder(Node* node, ostream& out = cout);
	void levelorder (ostream& out = cout);

	/* Overload the output operator. */
	friend ostream& operator<< (ostream& out, print_type& pt);

	/* Search a node in the BST */
	Node* search(int key);

	/* Inorder predecessor and succesor */
	Node* get_inorder_successor(Node* node);
	Node* get_inorder_successor(int value);

	Node* get_inorder_predecessor(Node* node);
	Node* get_inorder_predecessor(int value);

	/* Get parent of the node */
	Node* get_parent(Node* node);
	Node* get_parent(int value);

	/* Check if node is left or right child */
	bool is_left_child(Node* node);
	bool is_left_child(int value);

	bool is_right_child(Node* node);
	bool is_right_child(int value);

	/* Check if the node is root node */
	bool is_root(Node* node);
	bool is_root(int value);

	/* Check if the node has two child nodes */
	bool has_two_siblings(Node* node);
	bool has_two_siblings(int value);

	/* Check if the node has only one child node */
	bool has_only_one_sibling(Node* node);
	bool has_only_one_sibling(int value);

	/* Check if the node is a leaf node */
	bool is_leaf(Node* node);
	bool is_leaf(int value);

	/* Delete node with a specific value */
	bool delete_node(Node* node);
	bool delete_node(int value);

};

#endif
