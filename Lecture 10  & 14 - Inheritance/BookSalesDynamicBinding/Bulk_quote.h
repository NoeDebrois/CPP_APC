/*
 * Bulk.h
 *
 *  Created on: Nov 1, 2016
 *      Author: user
 */

#ifndef BULK_H_
#define BULK_H_

#include "Quote.h"

class Bulk_quote : public Quote { // Bulk_quote inherits
public:
 	// from Quote
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);

	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
private:
	std::size_t min_qty = 0; // minimum purchase for the discount to
 							// apply
	double discount = 0; // fractional discount to apply
};

#endif /* BULK_H_ */
