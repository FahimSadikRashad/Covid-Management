#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "login.cpp"
#include "Register.h"
#include "ReadWrite.cpp"
#include "user.h"
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
#include <windows.h>

using namespace std;

class Account : public login, public Register, virtual public ReadWrite
{
private:
    static int id;
    int choice;
    int number_of_id;
    bool sucess_flag;


public:
    static  vector<user *> new_user;

    Account();

    void getData(string user, string pass);

    void set_file(int ch);

    int only_login();

    void only_register(int);

    void messageE();

    bool check_file(string file);

    void Add_data(int ch);

    void set_success_flag(bool mode);

    bool get_success_flag();

    void messageR();

    void message();

    user *getNode();

    int static getID();

    int static get_register_number();

    int  getchoice();

    void save_register_number();

    void  setNOID();

    int getTotalID();

    ~Account();
};
#endif // ACCOUNT_H
