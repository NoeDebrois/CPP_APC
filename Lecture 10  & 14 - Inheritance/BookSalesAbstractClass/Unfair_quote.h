#ifndef UNFAIR_H_
#define UNFAIR_H_

#include "Disc_quote.h"

class Unfair_quote : public Disc_quote { // Disc_quote inherits
public:
 	// from Disc_quote
	Unfair_quote() = default;
	Unfair_quote(const std::string&, double, std::size_t, double);

	// overrides the base version in order to implement the
	// purchase discount policy
	double net_price(std::size_t) const override;

};

#endif /* UNFAIR_H_ */
