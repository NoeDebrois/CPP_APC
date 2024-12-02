#include <iostream>
#include <vector>
using std::vector;

int main(){
	vector<int>v;

	v.push_back(1);
	v.resize(10);
	for (auto it=v.begin(); it!=v.end();it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;
}
