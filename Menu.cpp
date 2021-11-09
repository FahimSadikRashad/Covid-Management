#include "Account.cpp"
#include "Admin.h"
#include"Person.cpp"
#include "data_filter.h"
#include "Patient.cpp"
#include "Staff.cpp"
#include "password_in.cpp"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
#include "windows.h"
#include "Date.cpp"
using namespace std;

string actual_user="";

int countLeapYears(Date &d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

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
            actual_user=user;
            gotoxy(39, 10);
            pass = password_in::getPass();
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
                    log_patient(user, true);
                else if(login == 2)
                    log_staff(user, true);
                else
                    log_admin(user, true);
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

    void log_patient(string user, bool animation){
        int choice = 100;
        string id = get_ID_based_user_name(user);
        while(choice != 0)
        {
            if(animation)
                animation2(5, 12, 15, 0);
            gotoxy(0, 4);
            cout << "\t\t\t\t WELCOME " << user <<
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: CHECK SYMPTOMS" <<
                "\n\t\t\t    2: VACCINE STATUS" <<
                "\n\t\t\t    3: VIEW PROFILE" <<
                "\n\t\t\t    4: REQUEST UPDATE" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
            Patient p;
            if(choice == 1){
                animation2(2, 15, 15, 0);
                Patient::check_symptoms();
                p.save_information_on_paitent(actual_user);
                animation2(1, 16, 12, 0);
                Patient::display();
                cout << "\n\t\t\t  Press Any Key to Go Back...";
                getch();
                system("cls");
            }
            if(choice == 2){
                animation2(2, 15, 12, 0);
                Patient::display();
                cout << "\n\t\t\t  Press Any Key to Go Back...";
                getch();
                system("cls");
            }
            if(choice == 3){
                animation2(2, 15, 15, 0);
                setFname("info.txt");
                gotoxy(0, 3);
                ReadWrite::display(id, user);
                cout << endl;
                cout << "\n\t\t\t  Press Any Key to Go Back...";
                getch();
                system("cls");
            }
            if(choice == 4){
                animation2(2, 15, 16, 0);
                gotoxy(0, 3);
                cout << "\t\t\t\t  UPDATE OPTIONS" <<
                    "\n\t\t\t\t------------------ " <<
                     "\n\t\t\t\t1: NAME" <<
                    "\n\t\t\t\t2: AGE" <<
                    "\n\t\t\t\t3: GENDER" <<
                     "\n\t\t\t\t4: OCCUPATION" <<
                     "\n\t\t\t\t5: EMAIL" <<
                     "\n\t\t\t\t6: ADDRESS" <<
                     "\n\t\t\t\t7: CONTACT NO" <<
                     "\n\n\t\t\t  ENTER OPTION NO: " <<
                     "\n\t\t\t  ENTER NEW VALUE: ";

                int u_choice;
                gotoxy(43, 13);
                cin >> u_choice;
                gotoxy(43, 14);
                string opt[7] = {"name", "age", "gender", "occupation", "email", "address", "phone"};
                fflush(stdin);
                string new_value;
                getline(cin, new_value);
                p.save_req(opt[u_choice-1], new_value, id, "patient");

                return_menu(user, 1);
            }
        }
        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void return_menu(string user, int menu_index){
        system("cls");
        animation2(3, 13, 12, 0);
        gotoxy(26, 8);
        cout << "R E Q U E S T  S A V E D\n\n\n\n\n";
        Sleep(1200);
        animation2(5, 12, 15, 0);
        if(menu_index == 1)
            log_patient(user, false);
        else if(menu_index == 2)
            log_staff(user, false);
        else
            log_admin(user, false);
    }

    void log_staff(string user, bool animation){
        int choice = 100;
        string id = get_ID_based_user_name(user);
        while(choice != 0)
        {
            if(animation)
                animation2(5, 12, 15, 0);
            gotoxy(0, 4);
            cout << "\t\t\t\t WELCOME " << user <<
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: SEARCH PATIENT" <<
                "\n\t\t\t    2: PARAMETER VIEW" <<
                "\n\t\t\t    3: VIEW PROFILE" <<
                "\n\t\t\t    4: EDIT REQUEST" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
            Patient p;
            if(choice == 1){
                animation2(2, 15, 12, 0);
                gotoxy(26, 8);
                cout << "ENTER USERNAME: ";
                string str;
                fflush(stdin);
                cin >> str;
                setFname("patient.txt");
                if(ReadWrite::onlyRead(str)){
                    string pid = get_ID_based_user_name(str);
                    animation2(5, 12, 15, 0);
                    setFname("info.txt");
                    gotoxy(0, 3);
                    ReadWrite::display(pid, str);
                    cout << "\n\n\t\t\t  Press Any Key to Go Back...";
                    getch();
                    system("cls");
                }
                else{
                    animation2(5, 12, 12, 0);
                    gotoxy(24, 8);
                    cout << "N O   P A T I E N T   F O U N D\n\n\n\n\n";
                    Sleep(1500);
                    log_staff(user, true);
                }
            }
            if(choice == 2){
                animation2(2, 15, 16, 0);

                staff s;
                s.Display_on_different_type();
            }
            if(choice == 3){
                animation2(2, 15, 15, 0);
                setFname("info.txt");
                gotoxy(0, 3);
                ReadWrite::display(id, user);
                cout << "\n\n\t\t\t  Press Any Key to Go Back...";
                getch();
                system("cls");
            }
            if(choice == 4){
                animation2(2, 15, 16, 0);
                gotoxy(0, 3);
                cout << "\t\t\t\t  UPDATE OPTIONS" <<
                    "\n\t\t\t\t------------------ " <<
                     "\n\t\t\t\t1: NAME" <<
                    "\n\t\t\t\t2: AGE" <<
                    "\n\t\t\t\t3: GENDER" <<
                     "\n\t\t\t\t4: OCCUPATION" <<
                     "\n\t\t\t\t5: EMAIL" <<
                     "\n\t\t\t\t6: ADDRESS" <<
                     "\n\t\t\t\t7: CONTACT NO" <<
                     "\n\n\t\t\t  ENTER OPTION NO: " <<
                     "\n\t\t\t  ENTER NEW VALUE: ";

                int u_choice;
                gotoxy(43, 13);
                cin >> u_choice;
                gotoxy(43, 14);
                string opt[7] = {"name", "age", "gender", "occupation", "email", "address", "phone"};
                fflush(stdin);
                string new_value;
                getline(cin, new_value);
                p.save_req(opt[u_choice-1], new_value, id, "staff");

                return_menu(user, 1);
            }
        }
        animation2(5, 12, 15, 0);
        m_welcome(0, false);
    }

    void req_menu(string user){
            animation2(2, 15, 13, 0);
                gotoxy(0, 6);
                cout << "\t\t\t\t1: VIEW REQUEST" <<
                        "\n\t\t\t\t2: APPROVE REQUEST" <<
                        "\n\t\t\t\t0: RETURN" <<
                        "\n\n\t\t\t  ENTER CHOICE: ";
                int rchoice = 100;
                cin >> rchoice;
                if(rchoice == 1){
                    system("cls");
                    gotoxy(0, 2);
                    ReadWrite::setFname("Req_info.txt");
                    read("");
                    cout << "ID    USER_TYPE    OPTION    NEW_VALUE    DATE_ADDED" << endl;
                    int lcount = 0;
                    for(auto i : v1){
                        lcount++;
                        if(lcount == 6){
                            lcount = 0, cout << endl;
                            continue;
                        }
                        cout << i << "    ";
                    }
                    cout << endl;
                    cout << "\n\n\t\t\t  Press Any Key to Go Back...";
                    getch();
                    animation2(15, 2, 15, 0);
                    log_admin(user, false);
                }
                if(rchoice == 2){
                    animation2(4, 13, 12, 0);
                    gotoxy(0, 8);
                    Admin a;
                    cout << "\t\t\t\tENTER USERID: ";
                    string userid;
                    cin >> userid;
                    a.update_on_things("id-"+userid);
                    animation2(5, 12, 12, 0);
                    gotoxy(24, 8);
                    cout << "R E Q U E S T   A P P R O V E D\n\n\n\n\n";
                    Sleep(1200);
                    animation2(5, 12, 15, 0);
                    log_admin(user, false);
                }
    }

    void log_admin(string user, bool animation){
        int choice = 100;
        string id = get_ID_based_user_name(user);
        while(choice != 0)
        {
            if(animation)
                animation2(5, 12, 15, 0);
            gotoxy(0, 3);
            cout << "\t\t\t\t WELCOME " << user <<
                "\n\t\t\t  ------------------------- " <<
                "\n\t\t\t    1: INBOX REQUESTS" <<
                "\n\t\t\t    2: SEARCH USER" <<
                "\n\t\t\t    3: UPDATE INFO" <<
                "\n\t\t\t    4: DELETE USER" <<
                "\n\t\t\t    5: PARAMETER VIEW" <<
                "\n\t\t\t    6: VIEW PROFILE" <<
                "\n\t\t\t    0: LOGOUT" <<
                "\n\n\t\t    Enter Choice : ";
            cin >> choice;
            if(choice == 1){
                req_menu(user);
            }
            if(choice == 2){
                animation2(2, 15, 12, 0);
                gotoxy(26, 8);
                cout << "ENTER USERNAME: ";
                string str;
                fflush(stdin);
                cin >> str;
                string pid = get_ID_based_user_name(str);
                animation2(5, 12, 15, 0);
                setFname("info.txt");
                gotoxy(0, 3);
                ReadWrite::display(pid, str);
                cout << "\n\n\t\t\t  Press Any Key to Go Back...";
                getch();
                animation = true;
            }
            if(choice == 3){
                animation2(2, 15, 16, 0);

                gotoxy(0, 2);
                cout << "\t\t\t\t  UPDATE OPTIONS" <<
                    "\n\t\t\t\t------------------ " <<
                     "\n\t\t\t\t1: NAME" <<
                    "\n\t\t\t\t2: AGE" <<
                    "\n\t\t\t\t3: GENDER" <<
                     "\n\t\t\t\t4: OCCUPATION" <<
                     "\n\t\t\t\t5: EMAIL" <<
                     "\n\t\t\t\t6: ADDRESS" <<
                     "\n\t\t\t\t7: CONTACT NO" <<
                     "\n\n\t\t\t  ENTER OPTION NO: " <<
                     "\n\t\t\t  ENTER NEW VALUE: " <<
                     "\n\t\t\t  ENTER USERNAME: ";

                int u_choice;
                gotoxy(43, 12);
                cin >> u_choice;
                gotoxy(43, 13);
                string opt[7] = {"name", "age", "gender", "occupation", "email", "address", "phone"};
                fflush(stdin);
                string new_value, username, id;
                getline(cin, new_value);
                gotoxy(43, 14);
                fflush(stdin);
                getline(cin, username);
                id = get_ID_based_user_name(username);
                setFname("info.txt");
                if(ReadWrite::update(id, opt[u_choice-1], new_value)){
                    animation2(1, 16, 12, 0);
                    gotoxy(22, 8);
                    cout << "U P D A T E   S U C C E S S F U L\n\n\n\n\n";
                    Sleep(1200);
                    animation2(5, 12, 15, 0);
                    log_admin(user, false);
                }
                else{
                    animation2(1, 16, 12, 0);
                    gotoxy(26, 8);
                    cout << "U P D A T E   F A I L E D\n\n\n\n\n";
                    Sleep(1200);
                    animation2(5, 12, 15, 0);
                    log_admin(user, false);
                }
            }
            if(choice == 4){
                animation2(2, 15, 12, 0);
                gotoxy(0, 8);
                cout << "\t\t\t    ENTER USERNAME: ";
                string username, id;
                fflush(stdin);
                getline(cin, username);
                id = get_ID_based_user_name(username);
                setFname("info.txt");
                if(ReadWrite::update(id, "", "")){
                    setFname("Patient.txt");
                    ReadWrite::update(username, "", "");
                    setFname("Staff.txt");
                    ReadWrite::update(username, "", "");
                    setFname("Admin.txt");
                    ReadWrite::update(username, "", "");
                    
                    animation2(5, 12, 12, 0);
                    gotoxy(22, 8);
                    cout << "D E L E T E   S U C C E S S F U L\n\n\n\n\n";
                    Sleep(1200);
                    animation2(5, 12, 15, 0);
                    log_admin(user, false);
                }
                else{
                    animation2(5, 12, 12, 0);
                    gotoxy(26, 8);
                    cout << "D E L E T E   F A I L E D\n\n\n\n\n";
                    Sleep(1200);
                    animation2(5, 12, 15, 0);
                    log_admin(user, false);
                }
            }
            if(choice == 5){
                animation2(2, 15, 16, 0);
                staff s;
                s.Display_on_different_type();
            }
            if(choice == 6){
                animation2(2, 15, 15, 0);
                setFname("info.txt");
                gotoxy(0, 3);
                ReadWrite::display(id, user);
                cout << "\n\n\t\t\t  Press Any Key to Go Back...";
                getch();
                animation = true;
            }
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
        get_catagory_present(get_occupation());
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
            gotoxy(26, 8);
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



