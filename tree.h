#ifndef TREE
#define TREE
#include <fstream>
#include <iostream>
#include <string>
#include "Treend.h"

using namespace std;

template<class ItemType>
class TreeType 
{

   public:
      TreeType();
      TreeType (const TreeType &original){CopyTree(root, original.root);}//deep copies the binary search tree
      void operator=(TreeType &orginalTree); //allows trees to be equal each other
      void Insert(ItemType value); //inserts nodes into a binary search tree
      void Print() ; //prints out the binary seach tree
      // ~TreeType(); //deconstructor
      bool isEmpty() {return root==0;}//tests whether the binary search tree is empty or not
      bool DeleteItem(ItemType value); // deletes specific values in the binary search tree
      ItemType getCurrentData(){return current -> data;};//returns room
      void moveCurrentLeft();//moves current to the left
      void moveCurrentRight();//moves current to the right
      void setCurrentToRoot();//moves current to the root aka the start
      friend class Treend;
  
   private:
      TreeNode<ItemType>* root; // pointer to root/current node
      TreeNode<ItemType> *current; //external pointer to the current node
      void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original); //used for copy constructor 
      bool InsertItem(TreeNode<ItemType>*&  root, ItemType value); //recursive function for Insert function
      void PrintTree(TreeNode<ItemType>* root); //recursive function for Print function, prints out node values
      void Destroy(TreeNode<ItemType>*& root);//used with the deconstructor, deletes dynamically allocated nodes
      bool Delete(TreeNode<ItemType>*& root, ItemType);//recursive function for DeleteItem function, deletes nodes from tree
      void FindMax(TreeNode<ItemType>* root, ItemType &data);//finds the max value in tree

};

#include "tree.cpp"
#endif
