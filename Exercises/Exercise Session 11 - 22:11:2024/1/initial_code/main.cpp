#include "DocumentStore.h"

int main()
{
    std::size_t id = 945;
    Document d0("Apple", id++);
    Document d1("Orange", id++);
    Document d2("Melon", id++);
    Document d3("Peach", id++);
    Document d4("Strawberry", id++);

    DocumentStore ds0(3);
    ds0.addDocument(d0);
    ds0.saveAsDraft(d1);

    DocumentStore ds1(ds0);
    ds1.addDocument(d2);
    ds1.addDocument(d3);

    DocumentStore ds2(2);
    ds2.addDocument(d1);
    ds2.addDocument(d4);
    ds2.saveAsDraft(d2);
    ds2.saveAsDraft(d3);

    DocumentStore ds3(3);
    ds2.addDocument(d0);
    ds2.addDocument(d1);
    ds3 = ds2;
    ds3.addDocument(d3);

    std::cout << "--------------- ds0 ---------------" << std::endl;
    ds0.print();

    std::cout << "\n--------------- ds1 ---------------" << std::endl;
    ds1.print();

    std::cout << "\n--------------- ds2 ---------------" << std::endl;
    ds2.print();

    std::cout << "\n--------------- ds3 ---------------" << std::endl;
    ds3.print();

    return 0;
}