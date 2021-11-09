#include "Person.h"
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Person::set_id()
{
    ReadWrite::add("id-"+to_string(Account::get_register_number()+getTotalID()));
}

void Person::set_name()
{
    fflush(stdin);
    getline(cin, name);
    add(name);
}

void Person::set_user_name()             /// setter function for name
{
    fflush(stdin);
    cout << "ID: " << getID() << endl;
    string temp =new_user[getID()]->getName();             /// should be auto generated!
    add(temp);
    cout << temp << endl;
}

void Person::set_age()               /// setter function for age
{
    fflush(stdin);
    cin >> age;
    add(age);
}

void Person::set_gender()            /// setter function for gender
{
    fflush(stdin);
    cin >> gender;
    add(gender);
}

void Person::set_occupation()      /// setter function for occupation
{
    fflush(stdin);
    cin >> occupation;
    add(occupation);
}

void Person::set_address()           /// setter function for address
{
    fflush(stdin);
    cin >> address;
    add(address);
}

void Person::set_phone()             /// setter function for phone
{
    fflush(stdin);
    cin >> phone;
    add(phone);
}

void Person::set_email()             /// setter function for email
{
    fflush(stdin);
    cin >> email;
    add(email);
}

/// all getter function  can be ignored  completely if needed
string Person::get_age()
{
    return age;
}

string Person::get_name()
{
    return name;
}

string Person::get_email()
{
    return email;
}

string Person::get_phone()
{
    return phone;
}

string Person::get_address()
{
    return address;
}

string Person::get_occupation()
{
    return occupation;
}

string Person::get_gender()
{
    return gender;
}

void Person::add_catagory(string str)
{
    setFname("Catagory.txt");
    add(str);
}
void Person::get_catagory_present(string str)
{
    cout << "occupation = " << str << endl;
    fstream f;
    f.open("Catagory.txt",ios::in);
    bool flag=false;
    string line;
    if(!f)
    {
        cout<<"--File not found--"<<endl;
    }
    else
    {
        while(f.good())
        {
            getline(f,line);
            if(line == str) flag=true;
            if(flag)
                break;
        }
        if(!flag)
        {
            add_catagory(str);
        }
    }
    f.close();
}

void Person::get_data()
{
    setFname("info.txt");
    set_id();
    set_name();
    set_age();
    set_email();
    set_phone();
    set_address();
    set_occupation();
    set_gender();
}
