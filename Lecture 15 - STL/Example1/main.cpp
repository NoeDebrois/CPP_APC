#include <iostream>
#include <list>

using std::list;

void insert_in_order(list<int> & l, int i);

int main(){
	list<int>l;

	insert_in_order(l, 1);
	insert_in_order(l, 3);
	insert_in_order(l, 2);

	for (auto it=l.cbegin(); it!=l.cend();it++)
		std::cout<< *it <<" ";
	std::cout<<std::endl;

}


void insert_in_order(list<int> & l, int i){

	if (l.empty())
		l.push_front(i);
	else{
		auto it=l.begin();
		while (it!=l.end() && *it<i)
			++it;
		l.insert(it,i);
	}
}



