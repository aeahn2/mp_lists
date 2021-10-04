/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
 #include <iostream>
 #include <unordered_set>
 #include <stack>
 #include <string>
#include <typeinfo>

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
    ListNode* head_ = NULL;
    ListNode* tail_ = NULL;
    int length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  List<T>::ListIterator iter = head_;
  return iter;
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  // std::cout << "destroy print: line " << __LINE__ << std::endl;
  // while (head_ != NULL) {
  //   std::cout << "destroy print: line " << __LINE__ << std::endl;
  //   //bool isNull = (head_->next == NULL);
  //   std::cout << "destroy print: head.next null? " << head_->next << std::endl;
  //   tail_ = head_->next;
  //   std::cout << "destroy print: line " << __LINE__ << std::endl;
  //   delete head_;
  //   std::cout << "destroy print: line " << __LINE__ << std::endl;
  //   head_ = tail_;
  //   std::cout << "destroy print: line " << __LINE__ << std::endl;
  // }
  // std::cout << "destroy print: line " << __LINE__ << std::endl;
  std::cout << "destroy print: line " << __LINE__ << std::endl;
  int len = this->length_;
  std::cout << "destroy print: line " << __LINE__ << std::endl;
  ListNode *curr = this->head_;
  while (len > 1) {
    std::cout << "destroy print: line " << __LINE__ << std::endl;
    ListNode *next = curr->next;
    std::cout << "destroy print: line " << __LINE__ << std::endl;
    delete curr;
    std::cout << "destroy print: line " << __LINE__ << std::endl;
    curr = next;
    std::cout << "destroy print: line " << __LINE__ << std::endl;
    len--;
    std::cout << "destroy print: line " << __LINE__ << std::endl;
  }
  std::cout << "destroy print: line " << __LINE__ << std::endl;
  // curr = this->tail_;
  // delete curr;
  //delete head_;
  //std::cout << "destroy print: line " << __LINE__ << std::endl;
  //delete tail_;
  //std::cout << "destroy print: line " << __LINE__ << std::endl;
  this->length_ = 0;
  std::cout << "destroy print: line " << __LINE__ << std::endl;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);

  if (this->head_ == NULL) {
    this->head_ = newNode;
    this->tail_ = newNode;
  } else {
    //&(this->head_)-> prev = newNode;
    newNode->next = this->head_;
    this->head_ = newNode;
  }
  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  std::cout << "insertBack print: line " << __LINE__ << std::endl;
  if (this->tail_ == NULL) {
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
    this->tail_ = new ListNode(ndata);
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
    this->head_ = this->tail_;
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
  } else {
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
    ListNode* back = new ListNode(ndata);
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
    ListNode **tailNode = &tail_;
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
    std::cout << "insertBack: (*tailNode)->next " << (((*tailNode)->next)==NULL) << std::endl;
    std::cout << "insertBack: back " << back << std::endl;
    (*tailNode)->next = back;
    //this->tail_->next = back;
    std::cout << "insertBack print: line " << __LINE__ << std::endl;
  }
  std::cout << "insertBack print: line " << __LINE__ << std::endl;
  length_++;
  std::cout << "insertBack print: line " << __LINE__ << std::endl;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  for (int i = 0; i < splitPoint || curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three
  * elements in the list starting for the first three elements. If the
  * end of the list has a set of 1 or 2 elements, no rotation all be done
  * on the last 1 or 2 elements.
  *
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  return NULL;
}

template <class T>
typename List<T>::ListNode* List<T>::getHead() {
  return this->head_;
}

template <class T>
typename List<T>::ListNode* List<T>::getTail() {
  return this->tail_;
}
