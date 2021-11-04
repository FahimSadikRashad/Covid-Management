#pragma once
#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

class Register
{
protected:
    static string f1;
    static int number_of_person_register;

public:
    virtual void Add_data() {};
    virtual void messageR() {};
    ~Register(){};
};
string Register::f1;
int Register::number_of_person_register=0;

#endif
