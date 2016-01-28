/* NAMES: Ryan Miyamoto(rmiyamot) and Sunbrye Ly(suly) 
 * PID: A10932226 and A1097284
 * DESCRIPTION:
 * DATE: 1/11/2015
 */   

#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP 
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

 BSTNode<Data>* curr;

public:


  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ // TODO
  BSTIterator(BSTNode<Data>* curr) {
    this->curr = curr;
  }

  /** Dereference operator. */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ // TODO
  bool operator==(BSTIterator<Data> const & other) const {
    //return the equality 
    return this->curr == other.curr;

  }

  /** Inequality test operator. */ // TODO
  bool operator!=(BSTIterator<Data> const & other) const {
    //return the inequality
    return this->curr != other.curr;
  }

};

#endif //BSTITERATOR_HPP 
