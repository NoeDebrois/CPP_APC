#include "Unfair_quote.h"


Unfair_quote::Unfair_quote(const std::string& s, double price, std::size_t min_q, double disc):
Disc_quote::Disc_quote(s,price,min_q,disc){};

double Unfair_quote::net_price(size_t cnt) const
{

	std::cout<<"Running net_price, Unfar_quote version"<<std::endl;
	if (cnt > quantity)
		return (cnt-quantity) * price + (1 - discount) * price * quantity;
	else
		return cnt * price;
}
