#include "Bulk_quote.h"



Bulk_quote::Bulk_quote(const std::string& s, double price, std::size_t min_q, double disc):
	Disc_quote::Disc_quote(s,price,min_q,disc){};


// if the specified number of items are purchased, use the discounted
// price
double Bulk_quote::net_price(size_t cnt) const
{

	std::cout<<"Running net_price, Bulk_quote version"<<std::endl;
	if (cnt <= quantity)
		return cnt * price;
	else
		return cnt * (1 - discount) * price;
}
