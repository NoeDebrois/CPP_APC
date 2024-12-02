/*
 * Bulk.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: user
 */

#include "Bulk_quote.h"



Bulk_quote::Bulk_quote(const std::string& s, double price, std::size_t min_q, double disc):
	Quote::Quote(s,price), min_qty(min_q), discount(disc){};


// if the specified number of items are purchased, use the discounted
// price
double Bulk_quote::net_price(size_t cnt) const
{

	std::cout<<"Running net_price, derived class version"<<std::endl;
	if (cnt <= min_qty)
		return cnt * price;
	else
		return cnt * (1 - discount) * price;
}

