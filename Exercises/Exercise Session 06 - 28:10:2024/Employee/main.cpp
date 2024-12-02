// Exercise Session 6 - 28/10/2024 - Noé Debrois
//
// We would like to recycle code at maximum. So, our class structure will look like :
// - 1 Employee class : there is no "employee" in the code, but we want an abstract class (class for which you cannot
// instantiate an object : it's just a prototype).
// - The other classes :
//      - Secretary : child class of Employee class ;
//      - Developer : derived class from the Employee base class (regular working hours + workshop hours have to be
//      taken into account);
//      - Manager : child class of DEVELOPER (this time : regular, workshop and manager hours).
//
// See the representation of exercise session 5 -> with blocks and arrows and the list of methods. It's a classical
// representation that can be used in exam.
//
// Chronological order of the session :
// 1) Write the constructors (obviously, they are Public members) ;
// 2) Print() functions : we can write it in the Base Class (let's say Employee) and the derived classes will inherit it
// and we don't need to do anything except call it if we don't want to behave differently for the derived classes. But
// if we want to make it behave differently we need overridding ;
// 3) set_work_hours(), set_wsh_hours(), set_m_hours() : set_work_hours() can be inherited in each and every 3 derived,
// but the other are specific to one or two types of employees (wsh : dev and manager, m : manager). Those are setters ;
// 4) salary_cal() member : for all three derived classes BUT we need it to behave differently in every classes ;
//
#include <iostream>
#include "Secretary.h"
#include "Developer.h"
#include "Manager.h"

int main (void)
{
    Secretary S("Anna","Rossi",1); // Declaration of a Secretary object with some args : we need to code the constructor
    Developer D("Mauro","Neri",2); // Idem for Developer
    Manager M("Gaia","Bruni",3);   // Idem for Manager
    // WARNING : we don't call the constructor for the abstract class Employee in the real code, only in the derived
    // classes. Because we don't want to build an Employee object (it does not exist).
    
    std::cout << "Secretary:" << std::endl;
    S.print(); // Here is a print function for Secretary : we have to implement it !
    S.set_work_hours(10);
    double Ssalary = S.salary_cal();
    std::cout << Ssalary << std::endl;
    
    std::cout << "Developer:" << std::endl;
    D.print(); // Here is a print function for Developer : we have to implement it !
    D.set_work_hours(10);
    D.set_wsh_hours(5);
    double Dsalary = D.salary_cal();
    std::cout << Dsalary << std::endl;
    
    std::cout << "Manager:" << std::endl;
    M.print(); // Here is a print function for Manager : we have to implement it !
    M.set_work_hours(10);
    M.set_wsh_hours(2);
    M.set_m_hours(3);
    double Msalary = M.salary_cal();
    std::cout << Msalary << std::endl;
    
    return 0;
}
