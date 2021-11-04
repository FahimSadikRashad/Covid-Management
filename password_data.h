#pragma once
#ifndef PASSWORD_DATA_H
#define PASSWORD_DATA_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

class password_data
{
private:
    /* data */
    string name;
    string pass_data;

public:
    password_data(/* args */);
    void setData(string s);
    void setPass(string s);

    string getName();
    string getPass();

    ~password_data();
};

#endif // PASSWORD_DATA_H
