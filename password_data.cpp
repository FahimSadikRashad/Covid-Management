#include "password_data.h"
#include <iostream>
#include <bits/stdc++.h>
#include"password_data.h"
using namespace std;

password_data::password_data(/* args */)
{
    setData("\0");
    setPass("\0");
}

void password_data::setData(string s)
{
    password_data::name = s;
}

void password_data::setPass(string s)
{
    password_data::pass_data = s;
}

string password_data::getName()
{
    return name;
}

string password_data::getPass()
{
    return pass_data;
}

password_data::~password_data()
{

}
