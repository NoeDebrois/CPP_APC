//
// Created by Federica Filippini on 30/10/23.
//

#include "rentShop.hpp"

unsigned int rentShop::getAvailableSkis() const {
  return localWarehouse.getSkis() + commonWarehouse->getSkis();
}

unsigned int rentShop::getAvailableSnowboards() const {
  return localWarehouse.getSnowboards() + commonWarehouse->getSnowboards();
}

void rentShop::finalizeRent(unsigned int sk, unsigned int sn) {
  if (localWarehouse.getSkis() < sk) {
    commonWarehouse->bookSkis(sk - localWarehouse.getSkis());
    localWarehouse.bookSkis(localWarehouse.getSkis());
  } else {
    localWarehouse.bookSkis(sk);
  }

  if (localWarehouse.getSnowboards() < sn) {
    commonWarehouse->bookSnowboards(sn - localWarehouse.getSnowboards());
    localWarehouse.bookSnowboards(localWarehouse.getSnowboards());
  } else {
    localWarehouse.bookSnowboards(sn);
  }
}

rentShop rentShop::create_copy() const {
  rentShop newshop(std::make_shared<skiWarehouse>(*commonWarehouse));
  newshop.localWarehouse = skiWarehouse(1,1);
  return newshop;
}

bool rentShop::rent(unsigned int sk, unsigned int sn) {
  if (getAvailableSkis() >= sk && getAvailableSnowboards() >= sn) {
    finalizeRent(sk, sn);
    return true;
  }
  return false;
}
