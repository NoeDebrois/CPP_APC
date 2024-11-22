#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {

private:
    time_t date;
    std::string name;

public:
    Event(time_t d, const std::string& n): date(d), name(n) {};
    
    time_t getTime (void) const;
    std::string getName (void) const;

    void setTime (time_t);
    void setName (const std::string&);
};

#endif // EVENT_H