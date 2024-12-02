#include "Date.h"

//Date::Date(int yy, int mm, int dd):y(yy), m(mm), (dd){};// initialize and check validity

Date::Date(int yy, int mm, int dd) // definition; note :: “member of”
	:y{yy}, m{mm}, d{dd} { /* … */ };

void Date::add_day(int n){// increase the Date by n days
	d += n;
}

void Date::print() const {
	std:cout<< y <<" " << m <<" "<< d<< std::endl;
}

int Date::month() const {
	return m;
}

int Date::day() const {
	return d;
}

int Date::year() const {
	return y;
}
