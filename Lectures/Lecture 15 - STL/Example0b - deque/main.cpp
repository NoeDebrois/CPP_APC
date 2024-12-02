#include <iostream>
#include <deque>



int main(){
	std::deque<int> d={1, 2, 3, 4};


	for (std::deque<int>::const_iterator it=d.cbegin(); it!=d.cend();it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;

	d.push_front(0);

	std::cout << d[0]  << std::endl;

    for (std::deque<int>::const_iterator it=d.cbegin(); it!=d.cend();it++)
        std::cout<< *it <<" ";
    std::cout<<std::endl;


}
