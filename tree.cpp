#include "tree.h"
#ifndef TREE_CPP
#define TREE_CPP

template<class ItemType>
void TreeType<ItemType>::operator=(TreeType<ItemType> &original)
{
	if(original == this)
		return; //ignore assigning self to self
	Destroy(root);
	CopyTree(root, original.root);
}


template<class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original)
{
	if (original == NULL)
	{
		copy = NULL;
	}
	else
	{
		copy = new TreeNode<ItemType>;
		copy -> data = original -> data;
		CopyTree(copy -> left, original -> left);
		CopyTree(copy -> right, original -> right);
	}
}



//template<class ItemType>
//TreeType<ItemType>::~TreeType()
//{
//   cout << "Destructor Running" << endl;
//   delete current;
//   destroy(root);
//}


template <class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& root)
{
	if (root == NULL)
	{
		return; //base case
	}
	else
	{
		Destroy(root -> left);
		Destroy(root -> right);
		root = NULL;
		delete root;
	}

}

template <class ItemType>
TreeType<ItemType>::TreeType()//Constructor
{
   root = 0;
   current = 0;
}

template <class ItemType>
void TreeType<ItemType>::Insert(ItemType item)
{
   InsertItem(root, item);
}


template<class ItemType>
bool TreeType<ItemType>::InsertItem(TreeNode<ItemType>*& root, ItemType value)
{

	if (root == NULL)
	{
		root = new TreeNode<ItemType>;
		if (root == NULL)
		{
			return false;
		}
		root -> left = NULL;
		root -> right = NULL;
		root -> data = value;
		return true;
	}
	else if (((root -> data).getfirstName()) > value.getfirstName())
	{
		return InsertItem(root -> left, value);
	}	
	else
	{
		return InsertItem(root -> right, value);
	}

}


template<class ItemType>
void TreeType<ItemType>::Print()
{
   PrintTree(root);
 
}


template <class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* root)
{
	if (root != NULL)
	{
		cout << (root -> data).getfirstName() << endl;
		PrintTree(root -> left);
		PrintTree(root -> right);
	}
}

template<class ItemType>
bool TreeType<ItemType>::DeleteItem(ItemType item)
{
   return Delete(root, item);
}


template<class ItemType>
void TreeType <ItemType>::FindMax(TreeNode <ItemType>* root, ItemType &data)
{
	while (root -> right != NULL)
	{
		root = root -> right;
	}
	data = root -> data;
}

template<class ItemType>
bool TreeType<ItemType>::Delete(TreeNode<ItemType>*& root, ItemType item)
{
	if (root == NULL)
		return false;
	else if (item < root -> data.getfirstName())
		return (Delete(root -> left, item));
	else if (item > root -> data.getfirstName())
		return (Delete(root -> right, item));
	else if (root -> data == item)
	{
		TreeNode<ItemType> *temp;
		if ((root -> left == NULL) && (root -> right == NULL))
		{
			temp = root;
			delete temp;
			root = NULL;
			return true;
		}
		else if ((root -> left == NULL) && (root -> right != NULL))
		{
			temp = root;
			root = root -> right;
			delete temp;
			return true;
		}
		else if ((root -> left != NULL) && (root -> right == NULL))
		{
			temp = root;
			root = root -> left;
			delete temp;
			return true;
		}
		else
		{
			int data;
			FindMax((root->left), data);
			root -> data = data;
			return Delete(root -> left , data);
		}
	} 
}




template<class ItemType>
void TreeType<ItemType>::moveCurrentLeft()
{
		current = current -> left;
}


template<class ItemType>
void TreeType<ItemType>::moveCurrentRight()
{
		current = current -> right;
}


template<class ItemType>
void TreeType<ItemType>::setCurrentToRoot()
{
		current = root;
}
#endif



