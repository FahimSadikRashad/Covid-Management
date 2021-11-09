#pragma once
#ifndef USER_H
#define USER_H
#include "password_data.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>


using namespace std;

class user : public password_data
{
private:
    int user_type; //1.Admin,2.staff,3.paitent
public:

    bool operator==(user &second)
    {
        if (this->getName() == second.getName() && this->getPass() == second.getPass())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void setUsertype(int n)
    {
        user_type = n;
    }
    int getUsertype()
    {
        return user_type;
    }
    ~user(){};
};

#endif // USER_H
