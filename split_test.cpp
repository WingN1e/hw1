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
  Node* linked_list = new Node(10, NULL); 
  for (int i = 9; i > 0; i--) {
    Node* temp = new Node(i, linked_list); 
    linked_list = temp; 
  }
  Node* odds = NULL;
  Node* evens = NULL;
  split(linked_list, odds, evens); 
  printList(odds); 
  cout << endl;
  printList(evens);
 
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