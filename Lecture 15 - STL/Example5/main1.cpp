#include <iostream>
#include <forward_list>

using namespace std;

int main(){

std::forward_list<int> flst={1,2,3,4};

auto prev = flst.before_begin();
// denotes element "off the start" of flst
auto curr = flst.begin();
while (curr != flst.end()) {
	if (*curr % 2)  //if the number is odd
	curr = flst.erase_after(prev);
	else {
		prev = curr;
	// move the iterators to denote the next
		++curr;
 	//element and one before the next element
		}
}

//print elements
curr = flst.begin();
while (curr != flst.end())
	std::cout << *(curr++) << " ";

std::cout << std::endl;

return 0;

}
