#ifndef CALENDAR_H
#define  CALENDAR_H

#include <iostream>
#include <vector>

#include "Event.h"

class Calendar {

private:
    /* YOUR CODE GOES HERE */ events;

public:
    /* constructor - YOUR CODE GOES HERE */

    void addEvent (const Event&);
    void updateEvent (time_t, const std::string&, time_t, const std::string&);
    void print (void) const;
};

#endif // CALENDAR_H