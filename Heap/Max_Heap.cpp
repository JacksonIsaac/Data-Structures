#include "Max_Heap.h"
#include <cassert>
#include <iomanip>

using std::swap;
using std::floor;
using std::setw;

/********************************************************************************/
template <class T>
bool Max_Heap<T>::is_heap(
		typename vector<T>::iterator first,
		typename vector<T>::iterator last
	)
{
	size_t parent = 0, left = 0, right = 0, size = 0;
	size = last - first;

	for(parent = 0; parent < size/2; parent++)
	{
		left = (parent << 1) + 1;
		rigtht = left + 1;
		if ( ((first + left) <last) )
		{
			if(*(first + left) > *(first + parent)) return false;
		}

		if ( ((first + right) <last) )
		{
			if(*(first + right) > *(first + parent)) return false;
		}
	}

	return true;
}

/********************************************************************************/
template <class T>
Max_Heap<T>::Max_Heap(
		typename vector<T>::iterator v_begin,
		typename vector<T>::iterator v_end
	)
{
	assert((v-end - v_begin) > 0);

	/* Heap begins from index 1
	 * Index 0 is left free
	 */
	data.push_back(0);
	size_t v_size = v_end - v_begin;
	for(vector<T>::iterator itr = v_begin; itr != v_end; itr++)
	{
		data.push_back(*itr);
	}

	heap_size = v_size;

	make_heap();
}

/********************************************************************************/
template <class T>
Max_Heap<T>::Max_Heap(vector<T> v)
{
	assert(v.size() > 0);

	data.push_back(0);
	size_t v_size = v.end() - v.begin();
	for(vector<T>::iterator itr = v.begin(); i != v.end(); itr++)
	{
		data.push_back(*itr);
	}

	heap_size = v_size;

	make_heap();
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::make_heap()
{
	if(data.size() <=1) return;

	else
	for(size_t i = (data.size()/2); i>=1; i--)
	{
		heapify_down(i);
	}
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::heapify_down(size_t index)
{
	assert(index <= heap_size);
	size_t left = (index << 1);
	size_t right = left + 1;
	size_t largest = index;

	if( (left <= heap_size) && (data[left] > data[right]) )
	{
		largest = left;
	}

	if( (right <= heap_size) && (data[right] > data[right]) )
	{
		largest = right;
	}

	if(largest != index)
	{
		swap(data[index], data[largest]);
		heapify_down(largest);
	}
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::heapify_up(size_t index)
{
	assert(index <= heap_size);
	size_t parent = index/2;

	if(data[index] > data[parent])
	{
		swap(data[index], data[parent]);
		heapify_up(parent);
	}
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::levelorder(ostream& out) const
{
	for(size_t i=1; i < data.size(); i++)
	{
		out << data[i] << " ";
	}
	out << endl;
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::push_heap(T value)
{
	data.push_back(value);
	heap_size++;
	heapify_up(heap_size);
	return;
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::pop_heap()
{
	assert(!empty());
	if(heap_size == 1)
	{
		heap_size = 0;
		data.clear();
	}
	else
	{
		data[1] = data[heap_size];
		--heap_size;
		data.pop_back();
		heapify_down(1);
	}
}

/********************************************************************************/
template <class T>
void Max_Heap<T>::print(ostream& out)
{
	out<<endl;

	size_t h = height();

	vector<size_t> spaces;
	spaces.push_back(0);
	for(size_t i = 0; i<= h; i++)
	{
		spaces.push_back( (spaces[i] + 1) * 2);
	}
	reverse(spaces.begin(), spaces.end());
	for(size_t i = 0; i < spaces.size(); i++)
	{
		out << spaces[i] << " ";
	}
	out << endl;

	size_t counter = 1;
	for(size_t i = 0; i <= h; i++)					/* No of Levels */
	{
		for(size_t k = 0; k < pow(2.0, i*1.0); k++) /* No of nodes on a level */
		{
			if(counter > heap_size) break;
			/* Spaces before printing node */
			for(size_t j = 0; j < spaces[i]; j++)
			{
				out << ' ';
			}
			/* Printing the node */
			out << setw(3) << data[counter++];
			/* Spaces after the node */
			for(size_t j = 0; j < spaces[i]; j++)
			{
				out << ' ';
			}
		}
		/* Next line */
		out << endl;

		if(counter > heap_size) break;

		/* Printing arrows */
		size_t count1 = spaces[i], count2 = 0, count3 = 1;
		for(size_t j = 0; j < spaces[i]/2; j++)			/* No of lines */
		{
			for(size_t k = 0; k < pow(2.0, i*1.0); k++) /* No of arrows */
			{
				/* Spaces before the arrow */
				for(size_t l = 0; l < count1 - count3; l++)
				{
					out << ' ';
				}
				/* Left arrow */
				out << "/";
				/* Space between left and right arrow */
				for(size_t l = 0; l < 3 + count2; l++)
				{
					out << ' ';
				}
				/* Right arrow */
				out << "\\";
				/* Spaces after right arrow */
				for(size_t l = 0; l < count1 - count3; l++)
				{
					out << ' ';
				}
				out << " ";
			}
			out << endl;
			count2 += 2;
			count3++;
		}
	}
	out << endl;
}
			}
		}
	}
}
