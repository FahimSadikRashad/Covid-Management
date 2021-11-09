#include "Staff.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
#include <conio.h>

using namespace std;
void staff::increment()
{
    staff_number++;
}
void staff::filter(string category)
{
    int line_no, reset = 7;
    /// defining position of line in "pos"to check the related attribute with the category
    if(category == "0" or category == "1")
        line_no = 6;/// vaccine status
    else
        line_no = 5; /// date

    v.clear();

    if(ReadWrite::fname == "Req_info.txt")
    {
        line_no = 5;
        reset = 6;

        string s1 = "ID";
        s1+= "    ";
        string s2 = "USER TYPE";
        s2.resize(9);
        s2+= "    ";
        string s3 = "REQ TYPE";
        s3.resize(10);
        s3+= "    ";
        string s4 = "UPDATE";
        s4.resize(10);
        s4+= "    ";
        string s5 = "ADDING DATE";
        s5.resize(11);
        s5+= "    ";

        string s = s1+s2+s3+s4+s5;
        v.push_back(s);
    }
    else
    {
        string s1 = "ID";
        s1+= "    ";
        string s2 = "NAME";
        s2.resize(10);
        s2+= "    ";
        string s3 = "SYMPTOMS MATCHING(%)";
        s3.resize(20);
        s3+= "    ";
        string s4 = "MONEY SPENT";
        s4.resize(11);
        s4+= "    ";
        string s5 = "ADDING DATE";
        s5.resize(11);
        s5+= "    ";
        string s6 = "VACCINE STATUS";
        s6.resize(14);
        s6+= "    ";

        string s = s1+s2+s3+s4+s5+s6;
        v.push_back(s);
    }

    bool flag = false;
    fstream f;
    f.open(fname, ios::in); /// Open file in read mode
    if (!f)
        cout << ReadWrite::fname << " file Not Found" << endl;
    else
    {
        string line, temp1 = "";
        int cnt = 0;

        while (f.good()) /// Iterate over the file until any error occurs
        {
            getline(f, line); /// storing the data of a person into a single string
            int length = line.size();
            if(reset == 7)
            {
                if(cnt == 0)
                    line.resize(2);
                if(cnt == 1)
                    line.resize(10);
                if(cnt == 2)
                    line.resize(20);
                else if(cnt == 3)
                    line.resize(11);
                else if(cnt == 4)
                    line.resize(11);
                else if(cnt == 5)
                    line.resize(14);
            }
            else
            {
                if(cnt == 0)
                    line.resize(2);
                if(cnt == 1)
                    line.resize(9);
                if(cnt == 2)
                    line.resize(10);
                if(cnt == 3)
                    line.resize(11);
            }

            temp1 += line;
            temp1 += "    ";
            cnt++;
            line.resize(length);
            if(cnt == line_no and line == category)
                flag = true;

            if(flag == true and cnt == reset)
            {
                v.push_back(temp1); /// only pushing the filtered data
                flag = false;
                temp1 = "";
                cnt = 0;
            }
            if(cnt == reset)
            {
                flag = false;
                temp1 = "";
                cnt = 0;
            }
        }

    }
    f.close();
}


void staff::Display_on_different_type()
{
    string search_tag;
    int choice = 100;
    while(choice != 0){
    gotoxy(0, 2);
    cout <<"\t\t\tF I L T E R   P A R A M E T E R S" <<
            "\n\t\t\t---------------------------------" <<
            "\n\t\t\t     1: OCCUPATION" <<
            "\n\t\t\t     2: LOCATION" <<
            "\n\t\t\t     3: AGE" <<
            "\n\t\t\t     4: GENDER" <<
            "\n\t\t\t     5: USERNAME" <<

            "\n\t\t\t     6: PATIENT DETAILS" << /// patient info
            "\n\t\t\t     7: VACCINE STATUS" << /// patient info
            "\n\t\t\t     8: REGISTRATION DATE" << /// patient
            "\n\t\t\t     9: UPDATE REQUEST BY DATE" << /// req info
            "\n\t\t\t     0: RETURN" <<
            "\n\n\t\t\tENTER CHOICE: "; 
    cin >> choice;
    system("cls");
    gotoxy(0, 2);
    if(choice == 1)
    {
        search_tag="profession";
    }
    if(choice == 2)
    {
        cout << "\t\t\t  ENTER LOCATION: ";
        cin >> search_tag;
    }
    if(choice == 3)
    {
        cout << "\t\t\t  ENTER AGE(LOWER-UPPER): ";
        int u,l;
        search_tag="";
        cin >>l;
        cout<<"-";
        cin>>u;
        search_tag+=to_string(l)+"-"+to_string(u);
    }
    if(choice == 4)
    {
        cout << "\t\t\t  ENTER GENDER: ";
        cin >> search_tag;
    }
    if(choice== 5)
    {
        search_tag="username";
    }
    if(choice <= 5)
    {
        setFname("info.txt");
        data_filter::read(search_tag);
        data_filter::display();
    }
    if(choice == 6)
    {
        cout << "\t\t\t  ENTER PATIENT ID: ";
        cin >> search_tag;

        ReadWrite::setFname("Paitien_info.txt");
        ReadWrite::display("id-"+search_tag);
    }
    if(choice == 7)
    {
        gotoxy(0,6);
        cout << "\t\t\t    1: VACCINATED" <<
                "\n\t\t\t    0: NOT VACCINATED" <<
                "\n\t\t\tENTER CHOICE: ";
        cin >> search_tag;

        ReadWrite::setFname("Paitien_info.txt");
        filter(search_tag);
        for (auto i : v)
            cout << i << endl;
    }
    if(choice == 8)
    {
        cout << "\t\t\tENTER DATE(DD-MM-YYYY): ";
        cin >> search_tag;
        ReadWrite::setFname("Paitien_info.txt");
        filter(search_tag);
        for (auto i : v)
            cout << i << endl;
    }
    if(choice == 9)
    {
        cout << "\t\t\tENTER DATE(DD-MM-YYYY): ";
        cin >> search_tag;

        ReadWrite::setFname("Req_info.txt");
        filter(search_tag);
        for (auto i : v)
            cout << i << endl;
    }
    if(choice == 0){
        break;
    }
    if(choice > 9){
        cout << "\n\n\t\t\t Please enter correct input";
    }
    cout << "\n\n\t\t\t  Press Any Key to Go Back...";
    getch();
    system("cls");
    gotoxy(0, 1);
    cout << "\t     ******************************************************";
    gotoxy(0, 16);
    cout << "\t     ******************************************************";

    }
}

int staff::staff_number=0;
