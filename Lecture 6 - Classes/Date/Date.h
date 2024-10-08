#include <iostream>

using namespace std;

// simple Date (some people prefer implementation details last)
class Date {
public:
	Date(int yy, int mm, int dd); // constructor: check for valid date and initialize
	void add_day(int n);       	// increase the Date by n days
	int month() const;
	int day() const;
	int year() const;
	void print() const;

private:
	int y,m,d;	// year, month, day
};
