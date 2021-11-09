#ifndef ADMIN_H
#define ADMIN_H
#include "Person.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Admin : public Person
{
private :
    static int Admin_number;

public:
    void static increment()
    {
        Admin_number++;
    }

    void set_file_on_update(string s)
    {
        if(s=="name"||s=="age"||s=="profession"||s=="email"||s=="address"||s=="phone")
            setFname("info.txt");
        else if(s=="percent" || s=="money" || s=="vaccinate")
            cout<<"Yes", setFname("Paitien_info.txt");
        else
            setFname("Req_info.txt");
    }

    void update_on_things(string id)
    {
        set_file_on_update("");
        string temp=getInfo(id,"reqtype"),temp1=getInfo(id,"update");
        //cout<<temp<<" "<<temp1<<" "<<temp2<<endl;

        set_file_on_update(temp);
        update(id,temp,temp1);
        set_file_on_update("");
        update(id, "", "");
    }

};

int Admin::Admin_number=0;

#endif