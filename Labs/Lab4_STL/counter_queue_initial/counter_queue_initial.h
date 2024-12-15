#ifndef EXERCISE__COUNTER_QUEUE_H
#define EXERCISE__COUNTER_QUEUE_H

#include <string>
#include <???>

namespace supermarket
{
class counter_queue
{
  /* Your data structure(s) goes here */

public:
  bool pick_number(const std::string &customer_id);

  std::string next_customer(void);

  bool empty(void) const;
};
}

#endif //EXERCISE__COUNTER_QUEUE_H
