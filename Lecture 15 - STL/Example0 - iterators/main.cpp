#include <iostream>
#include <vector>



int main(){
	const std::vector<int> v={1, 2, 3, 4};

	/* A very bad practice if
	   we change the containter
	   in the loop! 
	*/
	std::vector<int>::const_iterator begin=v.cbegin();
	std::vector<int>::const_iterator end=v.cend();

	for (std::vector<int>::const_iterator it=begin; it!=end;it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;

	// the way to go

	for (std::vector<int>::const_reverse_iterator it=v.crbegin(); it!=v.crend();it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;


}
