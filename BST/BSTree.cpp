// Mustafa Chowdhury, ge3306
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr )
{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree ( const BSTree<DataType,KeyType>& other )
{
	if (root != NULL)
		clear();

	if (other.root == NULL)
		root = NULL;

	else
		copyTree(other);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= ( const BSTree<DataType,KeyType>& other )
{
	if (this != &other)
	{
		if (root != NULL)
			clear();

		if (other.root == NULL)
			root = NULL;

		else
			copyTree(other);
	}
	return *this;
}

// --------------------------- copy -------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTree( const BSTree<DataType, KeyType> &otherTree )
{
	copyTreeHelper(root, otherTree.root);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copyTreeHelper( BSTreeNode *&p, const BSTreeNode *otherPtr )
{
	if (otherPtr == NULL)
		p = NULL;

	else
	{
		p = new BSTreeNode(otherPtr->dataItem, NULL, NULL);
		copyTreeHelper(p->left, otherPtr->left);
		copyTreeHelper(p->right, otherPtr->right);
	}
}

// ----------------- distructor --------------------------

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree ()
{
	clear();
}

// --------------------------------- insert ------------------------

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem )
{
	insertHelper(root, newDataItem);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insertHelper( BSTreeNode *&p, const DataType &newDataItem )
{
	if (p == NULL)
	{
		p = new BSTreeNode(newDataItem, NULL, NULL);
	}
	else if (p->dataItem.getKey() > newDataItem.getKey())
	{
		insertHelper(p->left, newDataItem);
	}
	else if (p->dataItem.getKey() < newDataItem.getKey())
	{
		insertHelper(p->right, newDataItem);
	}
	else
	{
		p->dataItem = newDataItem;
	}
}

// ------------------------- retrive -----------------------------------------

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const
{
	return retrieveHelper( root, searchKey, searchDataItem );
}

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrieveHelper( BSTreeNode *p, const KeyType& searchKey, DataType &searchDataItem ) const
{
	bool found = false;

	if (p == NULL)
	{
		found = false;
	}
	else if (p->dataItem.getKey() > searchKey)
	{
		found = retrieveHelper(p->left, searchKey, searchDataItem);
	}
	else if (p->dataItem.getKey() < searchKey)
	{
		found = retrieveHelper(p->right, searchKey, searchDataItem);
	}
	else
	{
		searchDataItem = p->dataItem;
		found = true;
	}

	return found;
}

//---------------------------- remove -------------------------------------------

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey )
{
	return removeHelper(root, deleteKey);
}

template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::removeHelper( BSTreeNode *&p, const KeyType& deleteKey )
{
	
	if (p == NULL)
		return false;

	else if (p->dataItem.getKey() > deleteKey)
	{
		removeHelper(p->left, deleteKey);
	}
	else if (p->dataItem.getKey() < deleteKey)
	{
		removeHelper(p->right, deleteKey);
	}
	else
	{
		if (p->left == NULL && p->right == NULL)
		{
			delete p;
			p = NULL;
			return true;
		}
		else if (p->left == NULL)
		{
			BSTreeNode *temp = p;
			p = p->right;
			
			delete temp;
			return true;
		}
		else if (p->right == NULL)
		{
			BSTreeNode *temp = p;
			p = p->left;
		
			delete temp;
			return true;
		}
		else
		{
			
			BSTreeNode *temp = p->left;
			
			
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			p->dataItem = temp->dataItem;
			removeHelper(p->left, temp->dataItem.getKey());	
		}
		
	}

}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::cutRightmost( BSTreeNode *&r, BSTreeNode *&delPtr )
{
}

//-------------------- write Key------------------------------------------

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys () const
{
	writeKeysHelper(root);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeKeysHelper( BSTreeNode *p ) const
{
	if (p != NULL)
	{
		writeKeysHelper(p->left);
		cout << p->dataItem.getKey() << " ";
		writeKeysHelper(p->right);
	}
}

//           ********** clear ************

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear ()
{
	clearHelper(root);
	root = NULL;
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::clearHelper( BSTreeNode *p )
{
	if (p != NULL)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
		p = NULL;
	}
	
}

//  ############ isEmpty ##############

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty () const
{
	return (root == NULL);
}


//        ********** get height *********

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight () const
{
	return getHeightHelper(root);
}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getHeightHelper( BSTreeNode *p ) const
{

	if (p == NULL)
	{
		return 0;
	}
	else if (p->left == NULL && p->right == NULL)
	{
		return 0;
	}
	else
	{
		int x, y;
		x = getHeightHelper(p->left);
		y = getHeightHelper(p->right);

		if (x >= y)
			return x + 1;
		else
			return y + 1;
	}









	/*
	else
	{
		int x, y;
		x = getHeightHelper(p->left);
		y = getHeightHelper(p->right);
		
		if (x >= y)
			return x+1;
		else
			return y+1;
	}*/
}

// ------------------------- count -------------------------

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount () const
{
	return getCountHelper(root);
}

template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode *p) const
{
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return (getCountHelper(p->left) + getCountHelper(p->right) + 1);
	}
}

// ----------------------- writeless than ---------------------------

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ) const
{
	writeLTHelper(root, searchKey);
}

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeLTHelper( BSTreeNode *p, const KeyType& searchKey ) const
{
	
	if (p != NULL)
	{
		writeLTHelper(p->left, searchKey);
		if (p->dataItem.getKey() < searchKey)
		{
			cout << p->dataItem.getKey() << " ";
			writeLTHelper(p->right, searchKey);
		}
	}

}


#include "show9.cpp"