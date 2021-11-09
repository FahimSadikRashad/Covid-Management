#pragma once
#ifndef READWRITE_H
#define READWRITE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

class ReadWrite
{
protected:
    vector<string> v1;
    vector<string> show;
    fstream file1;
    vector<string> show1;
    static string  fname ; string temp = "";


public:
    ReadWrite() {}
   // ReadWrite(string _fname) : fname(_fname) {}

    void setFname(string _fname);
    string getFname();

    /// Store each line from file to vector
    void read(string searchID);

    /// Return specific person's attribute based on passed key
    string getInfo(string searchID, string key);

    int getInfoAdditional(string searchOP);

    void add_additional_data(string s,string key);

    /// Convert the key into corresponding index of the vector
    int keyToIndex(string key);

    /// 0 Argument display func to show all information from the file
    void display();

    /// 1 Argument display func to show specific entry based on search ID
    void display(string searchID);

    void display(string searchID, string username);

    /// Simply write the passed data at the end of the file
    void add(string data);

    /// Update any attribute of the person like name, age, etc.
    /// If passed key and newData is "" then it deletes that person
    bool update(string searchID, string key, string newData);

    bool onlyRead(string name, string pass);
    bool onlyRead(string name);

    /// Delete specific person's entry from the file
    void erase_data(string searchID);
    void erase(string id,string reqtype,string up);
    string get_ID_based_user_name(string user_name);
    ~ReadWrite(){};
};



#endif
