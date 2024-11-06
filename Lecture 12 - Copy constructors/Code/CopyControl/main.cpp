#include "MyClass.h"

#include <iostream>
#include <vector>

int main()
{
  // #1: create first object
  std::cout << "#1: create first object" << std::endl;
  MyClass class_object_1("fede",10);
  std::cout << "class_object_1 = ";
  class_object_1.print();

  // #2: initialize second object
  std::cout << "\n#2: initialize second object" << std::endl;
  MyClass class_object_2(class_object_1);
  std::cout << "class_object_2 = ";
  class_object_2.print();

  // #3: initialize third object
  std::cout << "\n#3: initialize third object" << std::endl;
  MyClass class_object_3;
  std::cout << "class_object_3 = ";
  class_object_3.print();

  // #4: modify third object
  std::cout << "\n#4: modify third object" << std::endl;
  class_object_3 = class_object_1;
  std::cout << "new class_object_3 = ";
  class_object_3.print();

  // #5: initialize fourth object
  std::cout << "\n#5: initialize fourth object" << std::endl;
  MyClass class_object_4 = class_object_1;
  std::cout << "class_object_4 = ";
  class_object_4.print();

  // #6: modify fourth object
  std::cout << "\n#6: modify fourth object" << std::endl;
  class_object_4 = MyClass("ale", 5);
  std::cout << "new class_object_4 = ";
  class_object_4.print();

  // #7: initialize fifth object
  std::cout << "\n#7: initialize fifth object" << std::endl;
  MyClass class_object_5 = MyClass("albi", 1);
  std::cout << "class_object_5 = ";
  class_object_5.print();

  // #8: insert object in vector (1)
  std::cout << "\n#8: insert object in vector (1)" << std::endl;
  std::vector<MyClass> v1;
  v1.push_back(class_object_3);

  // #9: insert object in vector (2)
  std::cout << "\n#9: insert object in vector (2)" << std::endl;
  std::vector<MyClass> v2 = {class_object_4};

  // #10: insert object in vector (3)
  std::cout << "\n#10: insert object in vector (3)" << std::endl;
  std::vector<MyClass> v3(1);
  v3[0] = class_object_5;

  // #11: print vector (1)
  std::cout << "\n#11: print vector (1)" << std::endl;
  std::cout << "v1 = [" << std::endl;
  for (const MyClass& m : v1) {
    std::cout << "    ";
    m.print();
  }
  std::cout << "]" << std::endl;

  // #12: print vector (2)
  std::cout << "\n#12: print vector (2)" << std::endl;
  std::cout << "v2 = [" << std::endl;
  for (MyClass m : v2) {
    std::cout << "    ";
    m.print();
  }
  std::cout << "]" << std::endl;

  // #13: chain of assignments
  std::cout << "\n#13: chain of assignments" << std::endl;
  (class_object_2 = class_object_4) = class_object_5;
  std::cout << "class_object_2 = ";
  class_object_2.print();
  std::cout << "class_object_4 = ";
  class_object_4.print();
  std::cout << "class_object_5 = ";
  class_object_5.print();

  return 0;
}
