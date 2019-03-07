//Mustafa Chowdhury, ge3306

#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber)
{
	top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	if (top != NULL)
		clear();

	if (other.top == NULL)
		top = NULL;

	else
	{
		StackNode *current = other.top;
		StackNode *newNode, *temp;
		
		top = new StackNode(current->dataItem, NULL);
		temp = top;
		current = current->next;

		while (current != NULL)
		{
			newNode = new StackNode(current->dataItem, NULL);
			temp->next = newNode;
			temp = newNode;

			current = current->next;
		}

	}
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if (this != &other)
	{
		if (top != NULL)
			clear();

		if (other.top == NULL)
			top = NULL;

		else
		{
			StackNode *current = other.top;
			StackNode *newNode, *temp;
			
			top = new StackNode(current->dataItem, NULL);
			temp = top;

			current = current->next;

			while (current != NULL)
			{
				newNode = new StackNode(current->dataItem, NULL);
				temp->next = newNode;
				temp = newNode;

				current = current->next;
			}

		}
	}
	return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
		throw logic_error("List is full");

	top = new StackNode(newDataItem, top);

}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
	DataType t = 0;

	if (isEmpty())
		throw logic_error("List is empty");

	StackNode *temp = top;
	top = top->next;

	t = temp->dataItem;
	delete temp;

	return t;
}

template <typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode *temp;
	while (top != NULL)
	{
		temp = top;
		top = top->next;

		delete temp;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
    return (top == NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const
{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}