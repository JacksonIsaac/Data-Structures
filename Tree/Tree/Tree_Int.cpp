#include"Tree_Int.h"

/**********************************************************************************************************************************/
void Tree_Int::insertHelper(Node* node, int value)
{
	if(value == node->get_data())
	{
		cout << "Data already exists in the tree." << endl;
		return;
	}
	if(value < node->get_data())
	{
		if(node->get_left_ptr() == NULL)
		{
			node->set_left_ptr(new Node(value));
			tree_size++;
		}
		else
		{
			insertHelper(node->get_left_ptr(),value);
		}
	}
	else
	{
		if(node->get_right_ptr() == NULL)
		{
			node->set_right_ptr(new Node(value));
			Tree_Int::tree_size++;
		}
		else
		{
			insertHelper(node->get_right_ptr(),value);
		}
	}
}

/**********************************************************************************************************************************/
void Tree_Int::clear(Node* node)
{
	if(node == NULL) return;
	else
	{
		clear(node->get_left_ptr());
		clear(node->get_right_ptr());
		if(! is_root(node))
		{
			if(is_left_child(node))			get_parent(node)->set_left_ptr(NULL);
			else if(is_right_child(node))	get_parent(node)->set_right_ptr(NULL);
			delete node;
		}
		--tree_size;
	}
}

void Tree_Int::clear()
{
	clear(get_root());
	root = NULL;
	return;
}

/**********************************************************************************************************************************/
void Tree_Int::inorder (ostream& out){	inorder(get_root()), out << endl; }

void Tree_Int::inorder (Node* node, ostream& out)
{
	if(empty()) return;
	else if(node == NULL) return; 
	else{
		inorder(node->get_left_ptr()), out << node->get_data() << " ", inorder(node->get_right_ptr());
	}
}

/**********************************************************************************************************************************/
void Tree_Int::postorder (ostream& out){	postorder(get_root()), out << endl; }

void Tree_Int::postorder (Node* node, ostream& out)
{
	if(empty()) return;
	else if(node == NULL) return; 
	else{
		postorder(node->get_left_ptr()), postorder(node->get_right_ptr()), out << node->get_data() << " ";
	}
}

/**********************************************************************************************************************************/
void Tree_Int::preorder (ostream& out){	preorder(get_root()), out << endl; }

void Tree_Int::preorder (Node* node, ostream& out)
{
	if(empty()) return;
	else if(node == NULL) return; 
	else{
		out << node->get_data() << " ", preorder(node->get_left_ptr()), preorder(node->get_right_ptr());
	}
}

/**********************************************************************************************************************************/
void Tree_Int::levelorder (ostream& out){ levelorder(get_root()), out<<endl;	}
void Tree_Int::levelorder (Node* node, ostream& out)
{
	if(empty()) return;
	else if(node == NULL) return;
	
	queue<Node*> q;
	Node* next_node;
	q.push(node);
	while(!q.empty())
	{
		next_node = q.front(), q.pop();
		out << next_node->get_data() << " ";
		if(next_node->get_left_ptr() != NULL)
			q.push(next_node->get_left_ptr());
		if(next_node->get_right_ptr() != NULL)
			q.push(next_node->get_right_ptr());
	}
	return;
}

/**********************************************************************************************************************************/
Node* Tree_Int::search(int key)
{
	Node* curr_node = get_root();
	while(curr_node != NULL)
	{
		if(key == curr_node->get_data())
			return curr_node;
		else if(key < curr_node->get_data())
			curr_node = curr_node->get_left_ptr();
		else if(key > curr_node->get_data())
			curr_node = curr_node->get_right_ptr();
	}
	return NULL;
}

/**********************************************************************************************************************************/
Node* Tree_Int::get_inorder_successor(Node* node)
{
	if(node == NULL) return NULL;
	else
	{
		if(node->get_right_ptr() != NULL)
		{
			Node* curr_node = node->get_right_ptr();
			while(curr_node->get_left_ptr() != NULL)
			{
				curr_node = node->get_left_ptr();
			}
			return curr_node;
		}
		else
		{
			Node* succ_node = NULL;
			Node* curr_node = get_root();
			while(curr_node != NULL)
			{
				if(node->get_data() < curr_node->get_data())
				{
					succ_node = curr_node;
					curr_node = curr_node->get_left_ptr();
				}
				else if(node->get_data() > curr_node->get_data())
				{
					succ_node = curr_node;
					curr_node = curr_node->get_right_ptr();
				}
				else
					break;
			}
			return succ_node;
		}
	}
}

Node* Tree_Int::get_inorder_successor(int value)
{
	Node* node_ptr = search(value);
	return get_inorder_successor(node_ptr);
}

/**********************************************************************************************************************************/
Node* Tree_Int::get_inorder_predecessor(Node* node)
{
	if(node == NULL) return NULL;
	else
	{
		if(node->get_left_ptr() != NULL)
		{
			Node* curr_node = node->get_left_ptr();
			while(curr_node->get_right_ptr() != NULL)
			{
				curr_node = node->get_right_ptr();
			}
			return curr_node;
		}
		else
		{
			Node* succ_node = NULL;
			Node* curr_node = get_root();
			while(curr_node != NULL)
			{
				if(node->get_data() < curr_node->get_data())
				{
					succ_node = curr_node;
					curr_node = curr_node->get_left_ptr();
				}
				else if(node->get_data() > curr_node->get_data())
				{
					succ_node = curr_node;
					curr_node = curr_node->get_right_ptr();
				}
				else
					break;
			}
			return succ_node;
		}
	}
}

Node* Tree_Int::get_inorder_predecessor(int value)
{
	Node* node_ptr = search(value);
	return get_inorder_predecessor(node_ptr);
}

/**********************************************************************************************************************************/
Node* Tree_Int::get_parent(Node* node)
{
	if(node == NULL) return NULL;
	else
	{
		Node* curr_node = get_root(), *prev_node = NULL;
		while(curr_node != NULL)
		{
			if(node->get_data() == curr_node->get_data())
				return prev_node;
			else
			{
				if(node->get_data() < curr_node->get_data())
					curr_node = curr_node->get_left_ptr();
				else if(node->get_data() > curr_node->get_data())
					curr_node = curr_node->get_right_ptr();
			}
		}
	}
	return NULL;
}

Node* Tree_Int::get_parent(int value)
{
	Node* node = search(value);
	return get_parent(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::is_root(Node* node)
{
	if(node == NULL) return false;
	return (get_root() == node);
}

bool Tree_Int::is_root(int value)
{
	Node* node = search(value);
	return is_root(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::is_left_child(Node* node)
{
	if(node == NULL) return false;
	if(is_root(node))return false;
	else
	{
		if(get_parent(node) != NULL)
		{
			return (get_parent(node)->get_left_ptr() == node);
		}
	}
	return false;
}

bool Tree_Int::is_left_child(int value)
{
	Node* node = search(value);
	return is_left_child(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::is_right_child(Node* node)
{
	if(node == NULL) return false;
	if(is_root(node))
		return false;
	else
	{
		if(get_parent(node) != NULL)
		{
			return (get_parent(node)->get_right_ptr() == node);
		}
	}
	return false;
}

bool Tree_Int::is_right_child(int value)
{
	Node* node = search(value);
	return is_right_child(node);
}
/**********************************************************************************************************************************/
bool Tree_Int::has_two_siblings(Node* node)
{
	if(node == NULL) return false;
	return ((node->get_left_ptr() != NULL) && (node->get_right_ptr() != NULL));
}

bool Tree_Int::has_two_siblings(int value)
{
	Node* node = search(value);
	return has_two_siblings(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::has_only_one_sibling(Node* node)
{
	if(node == NULL) return false;
	return (((node->get_left_ptr() != NULL) && (node->get_right_ptr() == NULL))
			||((node->get_left_ptr() == NULL) && (node->get_right_ptr() != NULL)));
}

bool Tree_Int::has_only_one_sibling(int value)
{
	Node* node = search(value);
	return has_only_one_sibling(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::is_leaf(Node* node)
{
	if(node==NULL) return false;
	return ((node->get_left_ptr() == NULL) && (node->get_right_ptr() == NULL));
}

bool Tree_Int::is_leaf(int value)
{
	Node* node = search(value);
	return is_leaf(node);
}

/**********************************************************************************************************************************/
bool Tree_Int::delete_node(int value)
{
	Node* node = search(value);
	return delete_node(node);
}
bool Tree_Int::delete_node(Node* node)
{
	if(node == NULL) return false;
	else
	{
		if(is_leaf(node))
		{
			if(is_root(node))				root = NULL;
			else if(is_left_child(node))	get_parent(node)->set_left_ptr(NULL);
			else {
				assert(is_right_child(node));
				get_parent(node)->set_right_ptr(NULL);
			}
			delete node;
			--tree_size;
			return true;
		}
		else
		{
			if(has_only_one_sibling(node))
			{
				if(node->get_left_ptr() != NULL)
				{
					if(is_left_child(node))
					{
						get_parent(node)->set_left_ptr(node->get_left_ptr());
					}
					else if(is_right_child(node))
					{
						get_parent(node)->set_right_ptr(node->get_left_ptr());
					}
					else
					{
						assert(is_root(node));
						root = node->get_left_ptr();
					}
					delete node;
					--tree_size;
					return true;
				}
				else
				{
					assert(node->get_right_ptr() != NULL);
					if(is_left_child(node))
					{
						get_parent(node)->set_left_ptr(node->get_right_ptr());
					}
					else if(is_right_child(node))
					{
						get_parent(node)->set_right_ptr(node->get_right_ptr());
					}
					else
					{
						assert(is_root(node));
						root = node->get_right_ptr();
					}
					delete node;
					--tree_size;
					return true;
				}
			}
			else
			{
				assert(has_two_siblings(node));
				bool deletion_flag = 0;
				Node* inorder_successor_or_predecessor = NULL;
				if(deletion_flag == 0)
				{
					deletion_flag = 1;
					inorder_successor_or_predecessor = get_inorder_successor(node);
				}
				else
				{
					deletion_flag = 0;
					inorder_successor_or_predecessor = get_inorder_predecessor(node);
				}
				assert(inorder_successor_or_predecessor != NULL);

				int temp = inorder_successor_or_predecessor->get_data();

				delete_node(inorder_successor_or_predecessor);
				node->set_data(temp);
				return false;
			}
		}
	}
}