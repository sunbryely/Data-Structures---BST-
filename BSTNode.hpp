/* NAMES: Ryan Miyamoto(rmiyamot) and Sunbrye Ly(suly) 
 * PID: A10932226 and A1097284
 * DESCRIPTION:
 * DATE: 1/10/2015 
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
   //Completed, still needs to be tested -Sunbrye Ly
  BSTNode<Data>* successor() {
    //create a temp Node to traverse
    BSTNode<Data>* tempPointer = this; 

    //If the right node is not null, traverse right
    if(tempPointer->right != 0)
    {
      //Set traversal point to right node
      tempPointer = this->right;

      //Now traverse left all the way down
      if(tempPointer->left != 0)
      {
        tempPointer = this->left;
      }

      //If there are no left nodes, we have found the sucessor node
      else
      {
        return tempPointer;
      }

      //if there are more left nodes, traverse to the bottom
      while(tempPointer->left)
      {
        tempPointer = tempPointer->left;
      }

      //sucessor is bottommost left node
      return tempPointer;

    }

    //If right child is null, traverse to parent node
    else 
    {
      //return parent node as sucessor if node is not null
      if(this->parent != 0)
      {
        tempPointer = this->parent;
        return tempPointer;
      }
    }

      //Return 0 if there are no sucessor
      return 0;

  }

}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
