#include <iostream>
#include <list>
using std::list;

int main(){
	list<int>l;

	l.push_back(1);
	l.resize(10);
	for (auto it=l.begin(); it!=l.end();it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;
}
