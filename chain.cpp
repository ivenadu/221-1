#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
  Node* my_tail = tail();
  my_tail->next = new Node(ndata);
  my_tail->next->next = head_;

  length_ ++;

}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    Node* n1 = this->walk(head_, i);
    Node* n2 = this->walk(head_, j);
    Node* t = n1->next;
    n1->next = n2->next;
    n2->next = t;

    this->walk(head_, i-1)->next = n2;
    this->walk(head_, j-1)->next = n1;
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
   int m = length_ >> 1;
   for(int i = 0; i < m; i++){
       swap(i+1, length_ - i);
   }
}

/*
* Modifies the current chain by "rotating" every group of k nodes by one position.
* In every k-node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    int start = 0;
    for(int g = 0; g < length_ / k; g++, start += k)
        for(int i = 0; i < k-1; i++){
            swap(i+1 + start, i+2 + start);
        }
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    if(head_ == nullptr) return;

   Node *p1, *p2;
   p1 = head_;
   p2 = p1->next;
   
   while(p2 != head_){
      p1 = p2;
      p2 = p1->next;

      delete p1;
   } 
}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    head_ = new Node();
    head_->next = head_;
    length_ = 0;

   Node * p = other.head_->next;
   while(p != other.head_){
       this->insertBack(p->data);
       p = p->next;
   }

   width_ = other.width_;
   height_ = other.height_;
}

