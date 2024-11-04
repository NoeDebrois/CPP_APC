#ifndef RENTSHOP_HH
#define RENTSHOP_HH

#include "skiWarehouse.hpp"
#include <memory>

class rentShop {
private:
  std::shared_ptr<skiWarehouse> commonWarehouse;
  skiWarehouse localWarehouse;
  
  unsigned int getAvailableSkis() const;
  
  unsigned int getAvailableSnowboards() const;
  
  void finalizeRent(unsigned int sk, unsigned int sn);

public:
  explicit rentShop(const std::shared_ptr<skiWarehouse>& cW):
    commonWarehouse(cW), localWarehouse(2,2) {}

  rentShop create_copy() const;

  bool rent(unsigned int sk, unsigned int sn = 0);
};

#endif //RENTSHOP_HH