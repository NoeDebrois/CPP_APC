//============================================================================
// Author      : Noé Debrois (modified from APC course)
// Date		   : 24/10/2024
//============================================================================

#include <iostream>
#include <vector>
#include<cstdlib>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

// GOAL OF THIS SCRIPT : to show how to use DYNAMIC BINDING when we are in presence of a
// derived class and we don't want to re-code completely one of the base class' method.

// The following functions calculate and print the price for the given number of copies,
// applying any discounts (if needed).
// This function uses dynamic binding :
double print_total(const Quote &item, size_t n);
// Without dynamic binding we should create identical code for functions receiving BASE
// CLASS or DERIVED CLASS objects.  That's time-consuming and difficult to maintain :
double print_total2(const Quote item, size_t n);
double print_total3(const Bulk_quote item, size_t n);

int main() {
	Quote basic("123", 1);
	Bulk_quote bulk("123", 1, 10, 0.1);
    srand(0);
	// --> Basic has type Quote; bulk has type Bulk_quote

	// Using print_total, the type is dealt automatically :
	print_total(basic, 20); // calls Quote version of net_price
	print_total(bulk, 20); // calls Bulk_quote version of net_price

    std::cout << "Running print_total 3"<<std::endl;
	print_total3(bulk, 20); // calls Quote version of net_price!!!

	cout << bulk.net_price(20)<<std::endl;

    std::vector<Quote*> v;

    // Let's generate random Quote/Bulk_quote objects
    for (size_t i = 0; i<10; ++i){

        int rand_numb = rand() % 2;
        if (rand_numb ==0)
            v.push_back(new Quote(std::to_string(i+1),1));
        else
            v.push_back(new Bulk_quote(std::to_string(i+1),1, 10, 0.1));
    }
    std::cout << "Printing vector content"<< std::endl;

    for (size_t i = 0; i<v.size(); ++i)
        print_total(*v[i], 20);

    for (size_t i = 0; i<v.size(); ++i)
        delete v[i];

	return 0;
}

// Calculates and prints the price for the given number of copies,
// applying any discounts (if needed) :
//
// - VERSION THAT DOES IT INTELLIGENTLY :
double print_total(const Quote &item, size_t n)
{
	// DEPENDING ON THE TYPE OF THE OBJECT BOUND TO THE ITEM PARAMETER
	// [Information know AT RUN TIME only], it calls
	// EITHER Quote::net_price OR Bulk_quote::net_price
	double ret = item.net_price(n);
	cout << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
//
// - VERSION THAT DOES IT POORLY - ONLY FOR Quote TYPE :
double print_total2(const Quote item, size_t n)
{
	// Always calls : Quote::net_price
	double ret = item.net_price(n);
	cout << "ISBN: " << item.isbn() // calls Quote::isbn
	<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
//
// - VERSION THAT DOES IT POORLY - ONLY FOR Bulk_quote TYPE :
double print_total3(const Bulk_quote item, size_t n)
{
    // Always calls : Bulk_quote::net_price
    double ret = item.net_price(n);
    cout << "ISBN: " << item.isbn() // calls Quote::isbn
         << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}