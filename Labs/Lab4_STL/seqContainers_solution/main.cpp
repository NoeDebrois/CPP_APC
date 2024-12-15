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
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  // List (insert 1 after you have inserted the other numbers):
  l.push_back(2);
  l.push_back(3);
  l.push_front(1);
  // Efficient for lists. You cannot do it in vectors, there's no
  // push_front() since it would be inefficient

  // Forward list:
  fl.push_front(3);
  fl.push_front(2);
  fl.push_front(1);
  // has no push_back(), so you have to push_front() in reverse order

  // Deque:
  d.push_front(3);
  d.push_front(2);
  d.push_front(1);
  // we can do the same, let's go in reverse order to enjoy efficient
  // push_front()!

  // Writing elements to cout
  cout << "v, d, l, fl after Q1:" << endl;
  print(v);
  print(d);
  print(l);
  print(fl);
  cout << endl;


  // Q2) Let's add 1 to the first element through a reference to it
  // Vector:
  vector<int>::reference rv1 = v.front();
  rv1++;

  // List:
  deque<int>::reference rd1 = d.front();
  rd1++;

  // Forward list:
  list<int>::reference rl1 = l.front();
  rl1++;

  // Deque:
  forward_list<int>::reference rfl1 = fl.front();
  rfl1++;


  // Q3) Let's add 1 to the last element through a reference to it
  // Vector:
  vector<int>::reference rv2 = v.back();
  rv2++;

  // List:
  list<int>::reference rl2 = l.back();
  rl2++;

  // Forward list:
  // has no back() method, as it would not be efficient -> we cannot do it!!

  // Deque:
  deque<int>::reference rd2 = d.back();
  rd2++;

  // Writing elements to cout
  cout << "v, d, l, fl after Q2-3:" << endl;
  print(v);
  print(d);
  print(l);
  print(fl);
  cout << endl;


  // Q4) Let's print directly the first element of the list
  cout << "Q4 print l first element:" << endl;
  list<int>::value_type i = l.front();  // copy of the first element!
  cout << i << endl << endl;


  // Q5) Let's copy v in a second vector v2, in a deque d2, in a list l2
  // Into vector:
  vector<int> v2(v);  // same as vector<int> v2 = v;

  // Into deque:
  deque<int> d2(v.cbegin(), v.cend());

  // Into list:
  list<int> l2;
  l2.assign(l.cbegin(), l.cend());

  // Print containers
  cout << "v2, d2, l2 after Q5:" << endl;
  print(v2);
  print(d2);
  print(l2);
  cout << endl;


  // Q6) Let's copy v to the end of v2
  v2.insert(v2.end(), v.cbegin(), v.cend());
  cout << "v2 after Q6:" << endl;
  print(v2);
  cout << endl;


  // Q7) Let's copy v at the beginning of d2
  d2.insert(d2.begin(), v.cbegin(), v.cend());
  cout << "d2 after Q7:" << endl;
  print(d2);
  cout << endl;


  // Q8) Let's copy 1,2,3 at the beginning of l2 and 5,6 at its end
  l2.insert(l2.begin(), {1,2,3});
  l2.insert(l2.end(), {5,6});
  cout << "l2 after Q8:" << endl;
  print(l2);
  cout << endl;


  // Q9) Let's resize d and v so that they have 10 elements:
  // Deque:
  d.resize(10);

  // Vector (set new elements to 30):
  v.resize(10, 30);

  // Print containers
  cout << "d, v after Q9:" << endl;
  print(d);
  print(v);
  cout << endl;


  // Q10) Delete all elements in several ways
  // In vector from back:
  while (!v.empty())
      v.pop_back();

  // In deque from front:
  while (!d.empty())
      d.pop_front();

  // In list with iterators:
  l.erase(l.begin(), l.end());

  // In forward list with clear():
  fl.clear();

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
