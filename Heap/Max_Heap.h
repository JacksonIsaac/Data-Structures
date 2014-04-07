#ifndef __MAX_HEAP_H__
#define __MAX_HEAD_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <math>

using namespace std;

template <class T>
class Max_Heap
{
private:
	vector<T> data;
	size_t heap_size;

	/* Utility functions */
	void heapify_down(size_t index);

	void heapify_up(size_t index);

	void make_heap();

	void pop_heap_without_delete();

public:
	/* Constructors */
	Max_Heap(
			typename vector<T>::iterator v_begin(),
			typename vector<T>::iterator v_end()
			);
	Max_Heap(vector<T> v);

	/* Push elements into the heap */
	void push_heap(T value);

	/* Pop the root and re-heapify */
	void pop_heap(T value);

	/* Level Order traversal */
	void levelorder(ostream& out = cout) const;

	/* Print the Heap */
	void print(ostream& out = cout);

	/* Return the size of the heap */
	size_t size() const { return heap_size; }

	/* Check if empty */
	bool empty() const  { return heap_size == 0; }

	/* Return the root without deleting it */
	T peek() const { return data[1]; }

	/* Return the max element */
	T find_max() const { return peek(); }

	/* Return the height of the heap */
	int height()
	{
		return int(log(double(heap_size)) / log(2.0));
	}

	/* Check if the range [first,last) forms a heap */
	static bool is_heap (
						typename vector<T>::iterator first,
						typename vector<T>::iterator last,
						);

}

#include "Max_Heap.cpp"

#endif
