#include "rentShop.hpp"

int main() {
  std::shared_ptr<skiWarehouse> centralWarehouse = std::make_shared<skiWarehouse>(4,4);
  rentShop shop1(centralWarehouse);
  shop1.rent(3, 2);
  
  rentShop shop2(centralWarehouse);
  shop2.rent(0,5);
  
  rentShop shop3 = shop2; //.create_copy();
  centralWarehouse->resupply(5);
  shop3.rent(5,2);
  
  centralWarehouse->resupply();
  shop1.rent(5,0);
  return 0;
}
