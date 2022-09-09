/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
#include <string> 
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr* dat = new ULListStr(); 

  dat->push_back(to_string(1));
  dat->print();
  //prints 1

  dat->push_back(to_string(2));
  dat->push_back(to_string(3));
  dat->push_back(to_string(4));
  dat->print();
  //prints 1 2 3 4

  dat->pop_back();
  //pops the last value
  dat->print();
  //prints 1 2 3

  dat->pop_front();
  dat->print();
  //prints 2 3

  dat->push_front(to_string(1));
  dat->print();
  //prints 1 2 3 

  dat->push_front(to_string(9));
  dat->print();
  //prints 9 
  //prints 1 2 3

  dat->pop_front();
  dat->print();
  //prints 1 2 3

  dat->push_back(to_string(4));
  dat->push_back(to_string(5));
  dat->push_back(to_string(6));
  dat->push_back(to_string(7));
  dat->push_back(to_string(8));
  dat->push_back(to_string(9));
  dat->push_back(to_string(10));
  dat->print();
  //prints values from 1 to 10 filling up the array

  dat->push_back(to_string(1));
  dat->print();
  //prints out two nodes, second node having a value of only 1

  dat->pop_back();
  dat->print();
  //deletes second nodes, should print out 1 node only

  cout << dat->back() << endl;
  cout << dat->front() << endl;  
  cout << "\n";
  //prints 10 and 1

  cout << dat->get(0) << endl;
  //prints the first index which should be 1 
  dat->clear();
  cout << "\n";
  //clears the list

  dat->print();

  dat->push_front(to_string(1));
  dat->print();
  //prints 1

  dat->pop_front();
  dat->print();
  //should print no value

  dat->push_front(to_string(2));
  dat->print();
  //prints 2

  delete dat;
  return 0;
}
