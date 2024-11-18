/*
 * Quote.h
 *
 *  Created on: Nov 1, 2016
 *      Author: user
 */

#ifndef QUOTE_H_
#define QUOTE_H_

#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	// returns the total sales price for the specified number of items
	// derived classes will override and apply different discount
	// algorithms
	virtual double net_price(std::size_t n) const
    { std::cout<<"Running net_price, base class version"<<std::endl;
        return n * price; }

	virtual ~Quote() = default; // dynamic binding for the destructor
private:
	std::string bookNo; // ISBN number of this item
protected:
	double price = 0.0; // normal, undiscounted price
};

#endif /* QUOTE_H_ */
