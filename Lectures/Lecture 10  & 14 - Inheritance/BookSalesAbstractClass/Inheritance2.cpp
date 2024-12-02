#include <iostream>
#include "Quote.h"
#include "Unfair_quote.h"
#include "Bulk_quote.h"

using namespace std;

double print_total(const Quote &item, size_t n);

int main() {

	Quote basic("123", 1);
	Bulk_quote bulk("123", 1, 10, 0.1);
	Unfair_quote unfair("123", 1, 10, 0.1);

	print_total(basic, 20); // calls Quote version of net_price

	print_total( bulk, 20); // calls Bulk_quote version of net_price

	print_total(unfair, 20); // calls Unfair version of net_price

	return 0;
}

// calculate and print the price for the given number of copies,
// applying any discounts
double print_total(const Quote &item, size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	cout << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
