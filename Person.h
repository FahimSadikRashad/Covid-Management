#pragma once
#ifndef PERSON_H
#define PERSON_H
#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

class Person: public Account
{
   private:
    string name, age, email, phone, address, occupation, gender;

   public:
    string get_age();
    void set_age();
    string get_name();
    void set_name();
    string get_email();
    void set_email();
    string get_phone();
    void set_phone();
    string get_address();
    void set_address();
    string get_occupation();
    void set_occupation();
    string get_gender();
    void set_gender();
    void get_data();
    void set_id();
    void set_user_name();
    void get_catagory_present();
    void add_catagory();
    ~Person(){};
};

#endif
