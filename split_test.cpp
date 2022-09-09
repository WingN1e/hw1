#include "split.h"
#include <cstddef>
#include <iostream> 
using namespace std;

void printList(Node*& list) {
  cout << list->value << " ";
  if (list->next) {
    printList(list->next);
  }
}

int main () {
  //Uses a for loop to create a linked list going from 1 to 10
  Node* linked_list = new Node(10, NULL); 
  for (int i = 9; i > 0; i--) {
    Node* temp = new Node(i, linked_list); 
    linked_list = temp; 
  }
  Node* odds = NULL;
  Node* evens = NULL;
  split(linked_list, odds, evens); 
  //prints the list for the odd numbers
  printList(odds); 
  cout << endl;
  //prints the list for the even numbers
  printList(evens);
 
  //deletes the memory for even and odd
  Node* temp = evens;
  Node* temp2 = odds;
  while (evens->next && odds->next != NULL) {
    temp = evens->next;
    delete evens;
    evens = temp;
    temp2 = odds->next;
    delete odds;
    odds = temp2;

  }
  delete evens;
  delete odds;
}