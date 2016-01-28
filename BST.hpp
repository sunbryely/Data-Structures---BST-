/* NAMES: Ryan Miyamoto(rmiyamot) and Sunbrye Ly(suly) 
 * PID: A10932226 and A1097284 
 * DESCRIPTION:
 * DATE: 1/11/2015
 */

#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */
  virtual ~BST() {
    //Call deleteAll() to destroy the BST
    deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use >, <=, >=)
   */ // TODO
    virtual bool insert(const Data& item)
    {
      //Create a pointer to the root
      BSTNode<Data>* currentIndex = root; 

      //If this is the first insertion
      if(root == 0)
      {
          //Create a new node and set the data
          root = new BSTNode<Data>(item);
          //Link the children
          root->left = 0;
          root->right = 0;
          isize++;
          return true;
      }
      //If this is not the first insertion
      else
      {
        currentIndex = root; 
        while(currentIndex != 0)
        {
          //If the data to add is less than the current nodes data
          if(item < currentIndex->data)
          {
            //If the current nodes data is equal to the data being added
            if(currentIndex->data == item)
            {
                return false;
            }
            //If the left child is null
            else if(currentIndex->left == 0)
            {
              //Create a new left child node
              currentIndex->left = new BSTNode<Data>(item);
              //Set the parent of the left child to current
              currentIndex->left->parent = currentIndex;
              //Reset the current pointer
              currentIndex = 0;
              isize++;
              return true;
            }
            //If the left child is not null
            else
            {
              //Traverse left
              currentIndex = currentIndex->left;
            }
          }
          //If the data to add is greater than or equal to current nodes data
          else
          {
            //If current node data is equal to data to add
            if(currentIndex->data == item)
            {
              return false;
            }
            //If right child is null  
            else if(currentIndex->right == 0) 
            {
              //Create a new right child node
              currentIndex->right = new BSTNode<Data>(item);
              //Set the parent of the right child to current
              currentIndex->right->parent = currentIndex;
              //Reset the pointer
              currentIndex = 0;
              isize++;
              return true;
            }
            //If right child exists already
            else
            {
              //Traverse right
              currentIndex = currentIndex->right;
            }
          }
        }
      }
      return 0;
    }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use >, <=, >=)
   */ // TODO
  iterator find(const Data& item) const {

    BSTNode<Data>* currentNode = root;
    //While there is a currentNode
    while(currentNode)
    {
      //If the data to find is less than current node data
      if(item < currentNode->data)
      {
        //If a leftchild exists
        if(currentNode->left != 0)
        {
          //Traverse left
          currentNode = currentNode->left;
        }
        //If a left child does not exist return end of BST
        else
        {
          return end();
        }
      } 
      //If data to find is greater than current node data
      else if(item > currentNode->data)
      {
        //If a right child exists
        if(currentNode->right != 0)
        {
          //Traverse right
          currentNode = currentNode->right;
        }
        //If a right child doesnt exists return end of BST
        else
        {
          return end();
        }
      //If data if neither less than or greater (equal)  
      }
      else
      {
        //return an iterator pointing to the node
        return BSTIterator<Data>(currentNode);
      }
    }
    //return an iterator
    return typename BST<Data>::iterator(currentNode);
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
    return isize;

  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
    if(isize == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
    return typename BST<Data>::iterator(BST<Data>::first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */

    //If current node is null return
    if(n == 0)
    {
      return;
    }
    //Traverse left subtree
    inorder(n->left);
    //Print current node
    std::cout << n->data << std::endl;
    //Traverse right subtree
    inorder(n->right);
  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */

    //If current node is null return
    if(n == 0)
    {
      return; 
    }
    //Recursively delete left subtree
    deleteAll(n->left);
    //Recursively delete right subtree
    deleteAll(n->right);
    //Deletes the node
    delete n;
    n = 0;
  }


 };


#endif //BST_HPP
