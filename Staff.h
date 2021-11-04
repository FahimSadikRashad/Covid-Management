#ifndef STAFF_H
#define STAFF_H
#include "Person.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class staff : public Person
{
private :
    static int staff_number;
public :

     void static increment()
    {
        staff_number++;
    }
    void Display_on_different_type()//use data filter class
    {

    }
};

int staff::staff_number=0;

#endif
