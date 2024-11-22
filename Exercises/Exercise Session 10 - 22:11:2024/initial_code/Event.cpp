#include "Event.h"

time_t Event::getTime (void) const 
{
    return date;
}

std::string Event::getName (void) const 
{
    return name;
}

void Event::setTime (time_t d)
{
    date = d;
}

void Event::setName (const std::string& n)
{
    name = n;
}