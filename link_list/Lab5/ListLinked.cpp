// Mustafa Chowdhury, ge3306
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored = 0)
{
	head = NULL;
	cursor = NULL;
}

template <typename DataType>
List<DataType>::List(const List& other)
{
	if (head != NULL)
		clear();

	if (other.head == NULL)
	{
		head = NULL;
		cursor = NULL;
	}

	else
	{
		ListNode *temp;
		ListNode *currentNode;

		currentNode = other.head;

		head = new ListNode(currentNode->dataItem, NULL);

		cursor = head;

		currentNode = currentNode->next;

		while (currentNode != NULL)
		{
			temp = new ListNode(currentNode->dataItem, NULL);
			cursor->next = temp;
			cursor = temp;

			currentNode = currentNode->next;
		}
	}

}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	if (this != &other)
	{
		if (head != NULL)
			clear();

		if (other.head == NULL)
		{
			head = NULL;
			cursor = NULL;
		}

		else
		{
			ListNode *temp;
			ListNode *currentNode;

			currentNode = other.head;

			head = new ListNode(currentNode->dataItem, NULL);

			cursor = head;

			currentNode = currentNode->next;

			while (currentNode != NULL)
			{
				temp = new ListNode(currentNode->dataItem, NULL);
				cursor->next = temp;
				cursor = temp;

				currentNode = currentNode->next;
			}
		}

	}
	return *this;
}

template <typename DataType>
List<DataType>::~List()
{
	clear();
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	if (head == NULL)
	{
		head = new ListNode(newDataItem, NULL);
		cursor = head;
	}
	else if (head != NULL)
	{
		ListNode *newNode;
		newNode = new ListNode(newDataItem, NULL);
		cursor->next = newNode;
		cursor = newNode;
	}
	else
		cout << "The list is empty" << endl;

}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	if (head == NULL)
	{
		//throw logic_error("The list is empty");
		cout << "The list is emty" << endl;
		cursor = NULL;
	}
	else if (head == cursor)
	{
		ListNode *current;
		current = head;
		head = head->next;
		cursor = head;
		delete current;

	}
	else
	{
		ListNode * temp, *hold;
		temp = head;
		hold = cursor;

		while (temp->next != cursor)
		{
			temp = temp->next;
		}

		temp->next = cursor->next;
		cursor = temp;

		delete hold;
	}

}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	if (head == NULL)
	{
		throw logic_error("The list is empty");
		cout << "The list is empty" << endl;
	}
	else
	{
		ListNode *replaceItem, *temp;
		replaceItem = new ListNode(newDataItem, NULL);
		temp = head;
		while (temp->next != cursor)
			temp = temp->next;

		replaceItem->next = cursor->next;
		temp->next = replaceItem;

		temp = cursor;
		cursor = replaceItem;

		delete temp;
	}
}

template <typename DataType>
void List<DataType>::clear()
{
	ListNode *deleteNode;

	deleteNode = head;

	while (deleteNode != NULL)
	{
		head = head->next;
		delete deleteNode;
		deleteNode = head;
	}
	head = NULL;
	cursor = NULL;


}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
	}
	else
		cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
	}
	else
	{
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (head == NULL)
	{

		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
		return false;
	}
	else if (cursor->next == NULL)
		return false;
	else
	{

		cursor = cursor->next;
		return true;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
		return false;
	}
	else if (head == cursor)
	{
		cout << "There are no Item to the left of this list" << endl;
		return false;
	}
	else
	{
		ListNode *temp;
		temp = head;

		while (temp->next != cursor)
		{
			temp = temp->next;
		}

		cursor = temp;
		return true;
	}
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
	}
	else
	{
		DataType t;
		t = cursor->dataItem;
		return t;
	}
}

template <typename DataType>
void List<DataType>::moveToBeginning() throw (logic_error)
{
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is empty");
	}
	else if (cursor == head)
	{
		cout << "Cursor is already pointing to the 1st element" << endl;
		throw logic_error("Already on pointing 1st element");
	}
	else
	{
		ListNode *temp, *moveItem;
		temp = head;


		while (temp->next != cursor)
			temp = temp->next;

		temp->next = cursor->next;

		cursor->next = head;

		head = cursor;
	}

}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	ListNode *temp1, *temp2;
	temp1 = new ListNode(newDataItem, NULL);
	temp2 = head;
	if (head == NULL)
	{
		cout << "The list is empty" << endl;
		throw logic_error("The list is emplty");
	}

	else if (head == cursor)
	{
		temp1->next = cursor;
		head = temp1;
		cursor = temp1;
	}
	else
	{

		while (temp2->next != cursor)
		{
			temp2 = temp2->next;
		}

		temp1->next = cursor;

		temp2->next = temp1;

		cursor = temp1;
	}



}

#include "show5.cpp"


