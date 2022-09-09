#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  //checks if there are node
  if(head_ == NULL)
  {
    //creates new node
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    head_->next = NULL;
    head_->prev = NULL;
    //assigns the value
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
    size_ = 1;
    return;
  }
  //checks to see if there is room in the back of the array
  if (tail_->last != ARRSIZE) {
    //inserts value into the array
    tail_->val[tail_->last] = val;
    //moves last value back
    tail_->last++;
    //increments size
    size_ ++;
  }
  else 
  {
    //creates new node when node is full
    Item* node = new Item();
    node->next = NULL;
    node->prev = tail_;
    //points the current tail to new tail
    tail_->next = node;
    tail_ = node;
    //sets the first and last values of the new node
    tail_->first = 0;
    tail_->last = 1;
    //fills the first index of the new array
    tail_->val[0] = val;
    //increments size
    size_++;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL)
  {
    //creates new node
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    head_->val[9] = val;
    //assigns the 9th index the value
    head_->first = 9;
    head_->last = 10;
    size_ = 1;
    return;
  }
  //checks if there is room
  if (head_->first != 0) {
    //decrements the first and adds in the element into the array
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
  //there is no room
  else 
  {
    //creates new node
    Item* node = new Item();
    node->next = head_;
    head_->prev = node;
    head_ = node;
    //sets the first and last values of the new node
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    //assign the value to the back of the new node's array
    head_->val[head_->first] = val;
    //updates the size
    size_++;
  }
}

void ULListStr::pop_back() 
{
  if (head_ == NULL)
  {
    //empty array
    cout << "empty list popback" << endl;
    return;
  }
  else if (head_ == tail_ && head_->last - head_->first == 1)
  {
    //if there are multiple element in the array
    delete head_;
    head_ = NULL;
    size_--;
  }
  else if (tail_->last - tail_->first == 1)
  {
    //if there is only one element in the array
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = NULL;
    size_--;
  }
  else
  {
    tail_->last--;
    size_--;
  }
}

void ULListStr::pop_front()
{
  if (head_ == NULL)
  {
    //empty array
    return;
  }
  else if (head_ == tail_ && head_->last - head_->first == 1)
  {
    //if there are multiple element in the array
    delete head_;
    head_ = NULL;
    size_--;
  }
  else if (head_->last - head_->first == 1)
  {
    //if there is only one element in the array
    head_ = head_->next;
    delete head_->prev;
    head_->prev = NULL;
    size_--;
  }
  else
  {
    //increments
    head_->first++;
    size_--;
  }
}

std::string const & ULListStr::back() const 
{
  //gets last index
  tail_->last--;
  //returns the const reference to the last element
  return tail_->val[tail_->last];
}

std::string const & ULListStr::front() const 
{
  //returns the const reference to the first element
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const 
{
  //checks to see if loc is a valid index
  int index = loc;
  Item* node = head_;
  if (loc >= 0 && loc < ARRSIZE)
  {
    //the loc is valid 
    while (node != NULL)
    {
      int n = node->last - node->first;
      if (index < n)
      {
        //index is out of bounds
        return & node->val[node->first+index];
      }
      else 
      {
        //traverses through the list
        node = node->next;
        index -= n;
      }
    }
  }
  return NULL;
}

void ULListStr::print() {
  //current element is set to the head
  Item* curr = head_;
  if (curr == NULL)
  {
    //sees if array is empty
    cout << "Inside Empty List" << endl;
    cout << endl;
    return;
  }
  int n = 1;
  while (curr != NULL)
  {
    //prints current item
    cout << "Current Item " << n << ":" << endl;
    //increments current item
    n++;
    for (size_t i = curr->first; i < curr->last; i++)
    {
      //prints out the value of the array
      cout << curr->val[i] << " ";
    }
    cout << endl;
    curr = curr->next;
    cout << endl;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
