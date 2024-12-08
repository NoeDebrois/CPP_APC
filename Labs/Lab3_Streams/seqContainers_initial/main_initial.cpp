#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using std::vector;
using std::deque;
using std::list;
using std::forward_list;

using std::cout;
using std::endl;

void print(const std::vector<int> & v);
void print(const std::deque<int> & d);
void print(const std::list<int> & l);
void print(const std::forward_list<int> & fl);


int main() {
  // Initialize empty containers
  std::vector<int> v;
  std::deque<int> d;
  std::list<int> l;
  std::forward_list<int> fl;

  // Q1) Let's store 1,2,3
  // Vector:
  // TODO

  // List (insert 1 after you have inserted the other numbers):
  // TODO

  // Forward list:
  // TODO

  // Deque:
  // TODO

  // Writing elements to cout
  cout << "v, d, l, fl after Q1:" << endl;
  print(v);
  print(d);
  print(l);
  print(fl);
  cout << endl;


  // Q2) Let's add 1 to the first element through a reference to it
  // Vector:
  // TODO

  // List:
  // TODO

  // Forward list:
  // TODO

  // Deque:
  // TODO


  // Q3) Let's add 1 to the last element through a reference to it
  // Vector:
  // TODO

  // List:
  // TODO

  // Forward list:
  // this cannot be done!!

  // Deque:
  // TODO

  // Writing elements to cout
  cout << "v, d, l, fl after Q2-3:" << endl;
  print(v);
  print(d);
  print(l);
  print(fl);
  cout << endl;


  // Q4) Let's print directly the first element of the list
  // TODO


  // Q5) Let's copy v in a second vector v2, in a deque d2, in a list l2
  // Into vector:
  // TODO

  // Into deque:
  // TODO

  // Into list:
  // TODO

  // Print containers
  cout << "v2, d2, l2 after Q5:" << endl;
  print(v2);
  print(d2);
  print(l2);
  cout << endl;


  // Q6) Let's copy v to the end of v2
  // TODO
  cout << "v2 after Q6:" << endl;
  print(v2);
  cout << endl;


  // Q7) Let's copy v at the beginning of d2
  // TODO
  cout << "d2 after Q7:" << endl;
  print(d2);
  cout << endl;


  // Q8) Let's copy 1,2,3 at the beginning of l2 and 5,6 at its end
  // TODO
  cout << "l2 after Q8:" << endl;
  print(l2);
  cout << endl;


  // Q9) Let's resize d and v so that they have 10 elements:
  // Deque:
  // TODO

  // Vector (set new elements to 30):
  // TODO

  // Print containers
  cout << "d, v after Q9:" << endl;
  print(d);
  print(v);
  cout << endl;


  // Q10) Delete all elements in several ways
  // In vector from back:
  // TODO

  // In deque from front:
  // TODO

  // In list with iterators:
  // TODO

  // In forward list with clear():
  // TODO

  // All others are deleted through destructors ;)!!!
  return 0;
}




// Same kind of loops for each container
void print(const std::vector<int> & v){
    for(vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
        cout << *it << " ";
    cout << endl;
}

void print(const std::deque<int> & d){
    for(deque<int>::const_iterator it = d.cbegin(); it != d.cend(); it++)
        cout << *it << " ";
    cout << endl;
}

void print(const std::list<int> & l){
    for(list<int>::const_iterator it = l.cbegin(); it != l.cend(); it++)
        cout << *it << " ";
    cout << endl;
}

void print(const std::forward_list<int> & fl){
    for(forward_list<int>::const_iterator it = fl.cbegin(); it != fl.cend();
        it++)
        cout << *it << " ";
    cout << endl;
}
