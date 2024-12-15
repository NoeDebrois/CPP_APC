#include <iostream>

#include "counter_queue.h"

int main() {
  supermarket::counter_queue queue;
  std::cout << queue.empty() << std::endl;
  queue.pick_number("Alice");
  queue.pick_number("Bob");
  std::cout << queue.next_customer() << std::endl;
  std::cout << queue.empty() << std::endl;
  queue.pick_number("Charlie");
  std::cout << queue.next_customer() << std::endl;
  std::cout << queue.next_customer() << std::endl;
  std::cout << queue.empty() << std::endl;
  return 0;
}
