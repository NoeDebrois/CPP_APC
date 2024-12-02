#ifndef BULK_H_
#define BULK_H_

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote { // Bulk_quote inherits
public:
 	// from Disc_quote
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);

	// overrides the base version in order to implement the bulk
	// purchase discount policy
	double net_price(std::size_t) const override;
};

#endif /* BULK_H_ */
