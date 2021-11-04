#ifndef ADMIN_H
#define ADMIN_H
#include "Person.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Admin : public Person
{
private :
    static int Admin_number;

public:
     void static increment()
    {
        Admin_number++;
    }

    void update_on_things()
    {

    }
};

int Admin::Admin_number=0;

#endif
