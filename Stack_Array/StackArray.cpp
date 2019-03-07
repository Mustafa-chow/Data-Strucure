//Mustafa Chowdhury, ge3306

#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)
{
	if (maxNumber <= 0)
	{
		cout << "The size of the array must be positive" << endl;
		cout << "Creating the array size automatically" << endl;

		maxSize = Stack<DataType>::MAX_STACK_SIZE;
	}
	else
		maxSize = maxNumber;

	top = -1;
	dataItems = new DataType[maxSize];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	top = other.top;
	maxSize = other.maxSize;
	delete[] dataItems;

	dataItems = new DataType[maxSize];

	for (int i = 0; i < maxSize; i++)
	{
		dataItems[i] = other.dataItems[i];
	}
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	if (this != &other)
	{
		top = other.top;
		maxSize = other.maxSize;

		delete[] dataItems;

		dataItems = new DataType[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			dataItems[i] = other.dataItems[i];
		}
	}
	return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray()
{
	delete[] dataItems;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
		throw logic_error("List is full");

	top++;
	dataItems[top] = newDataItem;

}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("List is empty");

	DataType t=0;
	t = dataItems[top--];

	return t;
}

template <typename DataType>
void StackArray<DataType>::clear()
{
	top = -1;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{

	return (top == -1);
}

template <typename DataType>
bool StackArray<DataType>::isFull() const
{
	return (top == maxSize-1);
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}