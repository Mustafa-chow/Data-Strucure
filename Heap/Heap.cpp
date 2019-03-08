
#include "Heap.h"

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(int maxNumber)

// Creates an empty heap. Allocates enough memory for maxNumber
// data items.

: maxSize(maxNumber),
size(0)
{
	dataItems = new DataType[maxSize];
}

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(const Heap& other)

// Copy constructor

: maxSize(other.maxSize),
size(other.size)
{
	*this = other;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>:: operator= (const Heap& other)

{
	if (!(isEmpty()))
		clear();

	maxSize = other.maxSize;
	size = other.size;

	for (int i = 0; i < size; i++){
		dataItems[i] = other.dataItems[i];
	}

	return *this;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>:: ~Heap()

// Frees the memory used by a heap.

{
	clear();
	delete dataItems;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::insert(const DataType &newDataItem) throw (logic_error)

// Inserts newDataItem into a heap. This data item is initially
// inserted as the bottom rightmost data item in the heap. It is then
// moved upward until a valid heap is produced.

{
	if (isFull())
		throw logic_error("List is full.");
	else{
		dataItems[size] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType, KeyType, Comparator>::remove() throw (logic_error)

// Removes the data item with the highest priority (the root) from a
// heap and returns it. This data item is replaced with the bottom
// rightmost data item, which is moved downward until a valid heap is
// produced.

{
	if (isEmpty())
		throw logic_error("List is Empty.");
	size--;

	DataType returnData = dataItems[0];
	dataItems[0] = dataItems[size];

	int ind = 0;
	while (ind < size){
		Comparator compare;
		if ((ind * 2) + 2 <= size){

			if (compare(dataItems[(ind * 2) + 1].getPriority(), dataItems[(ind * 2) + 2].getPriority())){
				DataType temp = dataItems[ind];
				dataItems[ind] = dataItems[(ind * 2) + 2];
				dataItems[(ind * 2) + 2] = temp;
				ind = (ind * 2) + 2;
			}
			else if (compare(dataItems[(ind * 2) + 1].getPriority(), dataItems[ind].getPriority()) && compare(dataItems[ind].getPriority(), dataItems[(ind * 2) + 2].getPriority()))
				return returnData;
			else
			{
				DataType temp = dataItems[ind];
				dataItems[ind] = dataItems[ind + 1];
				dataItems[(ind * 2) + 1] = temp;
				ind = (ind * 2) + 1;
			}
		}
		else if ((ind * 2) + 1 <= size){
			if (compare(dataItems[ind].getPriority(), dataItems[(ind * 2) + 1].getPriority())){
				DataType temp = dataItems[ind];
				dataItems[ind] = dataItems[(ind * 2) + 1];
				dataItems[(ind * 2) + 1] = temp;
				ind = (ind * 2) + 1;
			}
			else
				return returnData;
		}
		else
			return returnData;
	}
	return returnData;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::clear()

// Removes all the data items from a heap.

{
	size = 0;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isEmpty() const

// Returns true if a heap is empty. Otherwise, returns false.

{
	if (size == 0)
		return true;
	return false;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isFull() const

// Returns true if a heap is full. Otherwise, returns false.

{
	if (size == maxSize)
		return true;
	return false;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::showStructure() const

// Outputs the priorities of the data items in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
	int j;   // Loop counter

	cout << endl;
	if (size == 0)
		cout << "Empty heap" << endl;
	else
	{
		cout << "size = " << size << endl;       // Output array form
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << dataItems[j].getPriority() << "\t";
		cout << endl << endl;
		showSubtree(0, 0);                        // Output tree form
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::showSubtree(int index, int level) const

// Helper function for the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
	int j;   // Loop counter

	if (index < size)
	{
		showSubtree(2 * index + 2, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)        // Tab over to level
			cout << "\t";
		cout << " " << dataItems[index].getPriority();   // Output dataItems's priority
		if (2 * index + 2 < size)                // Output "connector"
			cout << "<";
		else if (2 * index + 1 < size)
			cout << "\\";
		cout << endl;
		showSubtree(2 * index + 1, level + 1);        // Output left subtree
	}
}

//--------------------------------------------------------------------
//
//                        In-lab operations
//
//--------------------------------------------------------------------

//--------------------------------------------------------------------
//  In-lab Exercise 3
//--------------------------------------------------------------------

template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::writeLevels() const

// Outputs the data items in a heap in level order, one level per line.
// Only outputs the priority for each data item.

{

}

#include "show11.cpp"