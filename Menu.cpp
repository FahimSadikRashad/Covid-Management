#include "Account.cpp"
#include "Admin.h"
#include"Person.cpp"
#include "data_filter.h"
#include "Patient.cpp"
#include "Staff.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
#include "windows.h"
#include "Date.cpp"
using namespace std;



class Menu : public Person
{
protected:

public:
    Menu()
    {
        draw(2, 15, 0);
        gotoxy(18, 9);
        animation("COVID MANAGEMENT SYSTEM");
        m_welcome(1, true);
    }

    void static draw(int y1, int y2, int s)
    {
        system("cls");
        gotoxy(0, y1);
        cout << "\t\t **********************************************";
        if(s == 1)
        {
            gotoxy(0, 9);
            cout << "\t\t  C O V I D   M A N A G E M E N T   S Y S T E M";
        }
        gotoxy(0, y2);
        cout << "\t\t **********************************************";
        cout << endl;
        Sleep(30);
    }

    void animation(string str)
    {
        for(int i=0; i<(int)str.length(); i++)
        {
            if(str[i] == ' ')
                Sleep(250);
            cout << str[i];
            Sleep(40);
            cout << " ";
            Sleep(40);
        }
    }

    void static animation2(int beg, int end, int stop, int flag){
        for(int i=beg, j=end; ;i++,j--){
            if(i > stop)
                break;
            if(i>j){
                draw(j, i, 0);
            }
            else
                draw(i, j, flag);
        }
    }

    void m_login()
    {
        animation2(2, 15, 13, 0);
        int choice = 100;
        string user, pass;
        while(choice != 0)
        {
            gotoxy(0, 6);
            cout << "\t\t\t\t   L O G I N" <<
                "\n\t\t\t\t  ----------- " <<
                "\n\n\t\t\t    USERNAME : " <<
                "\n\t\t\t    PASSWORD : ";
            gotoxy(39, 9);
            cin >> user;
            gotoxy(39, 10);
            cin >> pass;
            getData(user, pass);
            int login = 0;
            login = only_login();
            system("cls");
            animation2(3, 13, 12, 0);
            if(login > 0){
                gotoxy(25, 8);
                cout << "L O G I N  S U C C E S S F U L\n\n\n\n\n";
                Sleep(1200);
                if(login == 1)
                    log_patient(user);
                else if(login == 2)
                    log_staff(user);
                else
                    log_admin(user);
            }
            else{
                gotoxy(26, 8);
                cout << "WRONG  USERNAME OR PASSWORD\n\n\n\n\n";
            }
            Sleep(1200);
            animation2(5, 12, 15, 0);
            m_welcome(0, false);
        }
    }

    void log_patient(string user){
        int choice = 100;
        while(choice != 0)
        {
            animation2(5, 12, 15, 0);
            gotoxy(0, 4);
            cout << "\t\t\t\t WELCOME " << user << 
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: CHECK SYMPTOMS" <<
                "\n\t\t\t    2: VACCINE STATUS" <<
                "\n\t\t\t    3: VIEW ALL INFO" <<
                "\n\t\t\t    4: EDIT REQUEST" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
            if(choice == 1){
                animation2(2, 15, 15, 0);
                Patient::check_symptoms();
                animation2(1, 16, 12, 0);
                Patient::display();
                cout << "\n\t\t\t  Press Any Key to Go Back...";
                getch();
            }
            if(choice == 2){
                animation2(2, 15, 12, 0);
                Patient::display();
                cout << "\n\t\t\t  Press Any Key to Go Back...";
                getch();
            }
            
        }
        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void log_staff(string user){
        animation2(5, 12, 15, 0);
        int choice = 100;
        while(choice != 0)
        {
            gotoxy(0, 4);
            cout << "\t\t\t\t WELCOME " << user << 
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: ADD PATIENT" <<
                "\n\t\t\t    2: VIEW PATIENT INFO" <<
                "\n\t\t\t    3: CHECK ALL INFO" <<
                "\n\t\t\t    4: EDIT REQUEST" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
             
        }
        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void log_admin(string user){
        animation2(5, 12, 15, 0);
        int choice = 100;
        while(choice != 0)
        {
            gotoxy(0, 4);
            cout << "\t\t\t\t WELCOME " << user << 
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: CHECK REQUESTS" <<
                "\n\t\t\t    2: VIEW PATIENT INFO" <<
                "\n\t\t\t    3: CHECK ALL INFO" <<
                "\n\t\t\t    4: UPDATE INFO" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
            
        }
        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void m_register()
    {
        animation2(3, 14, 15, 0);
        int choice = 100;
        while(choice != 0)
        {
            gotoxy(0, 4);
            cout << "\t\t\t\tR E G I S T E R" <<
                 "\n\t\t\t\t--------------- " <<
                 "\n\n\t\t\t\t  1: PATIENT" <<
                 "\n\t\t\t\t  2: STAFF" <<
                 "\n\t\t\t\t  3: ADMIN" <<
                 "\n\t\t\t\t  0: RETURN" <<
                 "\n\n\t\t\t\tEnter Choice: ";
            cin >> choice;
            if(choice >= 1 && choice <= 3)
                r_entry(choice);
            else
                m_welcome(0, true);
        }
    }

    void r_entry(int choice)
    {
        animation2(2, 15, 15, 0);
        string user, pass;
        gotoxy(0, 3);
        cout << "\t\t\t\tR E G I S T E R" <<
                 "\n\t\t\t\t---------------- " <<
                 "\n\t\t\tUSERNAME   : " <<
                 "\n\t\t\tPASSWORD   : " <<
                 "\n\t\t\tNAME       : " <<
                 "\n\t\t\tAGE        : " <<
                 "\n\t\t\tGENDER     : " <<
                 "\n\t\t\tOCCUPATION : " <<
                 "\n\t\t\tEMAIL      : " <<
                 "\n\t\t\tADDRESS    : " <<
                 "\n\t\t\tCONTACT NO : ";
                 
        gotoxy(37, 5);
        cin >> user;

        if(get_ID_based_user_name(user)=="-1"){
        setFname("info.txt");
        set_id();
        gotoxy(37, 6);
        cin >> pass;
        gotoxy(37, 7);
        set_name();
        gotoxy(37, 8);
        set_age();
        gotoxy(37, 9);
        set_gender();
        gotoxy(37, 10);
        set_occupation();
        gotoxy(37, 11);
        set_email();
        gotoxy(37, 12);
        set_address();
        gotoxy(37, 13);
        set_phone();
        getData(user, pass);
        set_user_name();
        add("");
        if(choice == 1){
            only_register(1);
        }
        else if(choice == 2){
            only_register(2);
        }
        else if(choice == 3){
            only_register(3);
        }
        cout<<get_register_number()<<endl;
        animation2(2, 15, 12, 0);
        gotoxy(18, 8);
        cout << "R E G I S T R A T I O N  S U C C E S S F U L\n\n\n\n\n";
        }
        else{
            number_of_person_register--;
            animation2(2, 15, 12, 0);
            gotoxy(18, 8);
            cout << "U N S U C C E S S F U L\n\n\n\n\n";
        }

        Sleep(1200);

        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void m_welcome(int m, bool animation)
    {
        if(animation)
            animation2(2, 15, 14, m);
        int choice = 100;
        while(choice != 0)
        {
            gotoxy(0, 5);
            cout << "\t\t\t  COVID  MANAGEMENT  SYSTEM" <<
                 "\n\t\t\t  ------------------------- " <<
                 "\n\n\t\t\t\t1: LOGIN" <<
                 "\n\t\t\t\t2: REGISTER" <<
                 "\n\t\t\t\t0: EXIT" <<
                 "\n\n\t\t\t  Enter Choice: ";
            cin >> choice;
            if(choice == 1)
                m_login();
            else if(choice == 2)
                m_register();
            else
            {
                animation2(3, 14, 12, 0);
                gotoxy(26, 8);
                cout << "E X I T  S U C C E S S F U L\n\n\n\n\n";
                exit(1);
            }
        }
    }
    virtual ~Menu()
    {

    }
};



