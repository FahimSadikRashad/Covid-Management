#ifndef STAFF_H
#define STAFF_H
#include "Person.h"
#include "data_filter.cpp"
//#include "ReadWrite.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class staff :public data_filter, public Person
{
private :
    static int staff_number;
    vector<string>v;
public :

    void static increment();
    void filter(string category);
    void Display_on_different_type();//use data filter class

};

#endif
