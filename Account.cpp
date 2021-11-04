#include "Account.h"
using namespace std;

Account::Account()
{
    setNOID();
};

void Account::getData(string user, string pass)
{
    new_user.push_back(getNode());
    new_user[id]->setData(user);
    new_user[id]->setPass(pass);
}

void  Account::set_file(int ch)
{
    if (ch == 3)
    {
        f1 = "Admin.txt";
        f = "Admin.txt";
    }
    else if (ch == 2)
    {
        f1 = "Staff.txt";
        f = "Staff.txt";
    }
    else if(ch == 1)
    {
        f1 = "Patient.txt";
        f = "Patient.txt";
    }
}

int Account::only_login()
{
    if(check_file("Patient.txt") || check_file("Staff.txt") || check_file("Admin.txt"))
    {
        Account::id++;
        sucess_flag=true;
        if(fname == "Patient.txt")
            return 1;
        else if(fname == "Staff.txt")
            return 2;
        else
            return 3;
    }
    else
    {
        sucess_flag=false;
        return 0;
    }
}

bool Account::check_file(string file)
{
    setFname(file);
    return onlyRead(new_user[id]->getName(), new_user[id]->getPass());
}

void Account::Add_data(int ch)
{
    set_file(ch);
    string temp = "";
    temp += new_user[id-1]->getName() + " " + new_user[id-1]->getPass();
    setFname(f1);
    add(temp);
}

void Account::set_success_flag(bool mode)
{
    sucess_flag=mode;
}

bool Account::get_success_flag()
{
    return sucess_flag;
}

void Account::save_register_number()
{
    setFname("Additional_info.txt");
    string temp="",temp1="ID";
    number_of_id+=get_register_number();
    add_additional_data(temp1,to_string(number_of_id));
}

void Account::only_register(int ch)
{
    Account::id++;
    Add_data(ch);
    save_register_number();
    number_of_person_register++;
}

void Account::messageE()
{
    cout << "Your choice number is wrong !!Try again !!!" << endl;
}

void Account::messageR()
{
    cout << "Do you have a account? " << endl
         << "1.Yes " << endl
         << "2.NO " << endl;
}

void Account::message()
{
    cout << "Do you want to continue or try again ? " << endl
         << "1.Yes " << endl
         << "2.NO " << endl;
}

user* Account::getNode()
{
    return new user();
}

int  Account::getchoice()
{
    return choice;
}

int Account::get_register_number()
{
    return number_of_person_register;
}

int Account::getTotalID()
{
    return number_of_id;
}

void  Account::setNOID()
{
    setFname("Additional_info.txt");
    number_of_id= getInfoAdditional("ID");
}

Account::~Account()
{
    cout<<"Account destructor"<<endl;
    setFname("Additional_info.txt");
    string temp="",temp1="ID";
    number_of_id+=get_register_number();
    add_additional_data(temp1,to_string(number_of_id));
}

int  Account::getID()
{
    return  id;
}

vector<user *>Account::new_user;
int Account::id = 0;