#include "ReadWrite.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;


void ReadWrite::setFname(string _fname) /// set the file name
{
    //cout<<fname<<"from inside Fname"<<endl;
    fname = _fname;
}
 string ReadWrite::getFname()
    {
        return fname;
    }

void ReadWrite::read(string searchID) /// Store each line from file to vector
{
    v1.clear();
    show.clear();
    bool flag = false;
    file1.open(fname, ios::in); /// Open file in read mode
    if (!file1)
        cout << "File Not Found" << endl;
    else
    {
        string line, temp = "";
        int cnt = 0;

        while (file1.good()) /// Iterate over the file until any error occurs
        {
            getline(file1, line);

            if (searchID == "") /// Store whole file to vector when "" is
            {
                if(cnt == 1)
                    line.resize(18);
                else if(cnt == 3)
                    line.resize(6);
                else if(cnt == 4)
                    line.resize(11);
                else if(cnt == 5)
                    line.resize(10);
                temp += line;
                temp += "    ";
                cnt++;
                if(cnt == 10 && getFname()=="info.txt")
                {
                    show.push_back(temp);
                    temp = "";
                    cnt = 0;
                }
                else if (cnt==7 && getFname()=="Paitien_info.txt")
                {
                    show.push_back(temp);
                    temp = "";
                    cnt = 0;
                }
                else if (cnt==6 && getFname()=="Req_info.txt")
                {
                    show.push_back(temp);
                    temp = "";
                    cnt = 0;
                }
                v1.push_back(line);
                continue; /// Only this if block is active
            }

            if (line == searchID) /// Use flag to active nested loop to store one
                flag = true;      /// person's data until the next one reaches
            if (flag)
            {
                getline(file1, line);
                while (line != "") /// End marker of each person. In this case
                {
                    /// end marker is set as empty line ""
                    temp += line + "    ";
                    v1.push_back(line);
                    getline(file1, line);
                }
                show.push_back(temp); /// all information of a person is stored
                flag = false;          /// in a single string temp
            }
        }
    }
    file1.close();
}


/// Return specific person's attribute based on passed key
string ReadWrite::getInfo(string searchID, string key)
{
    read(searchID); /// Store 1 person's data to the vector
    if (v1.empty())
        return "Not Found";
    int index = keyToIndex(key);
    return v1[index];
}


int ReadWrite::getInfoAdditional(string searchOP)
{
    string temp,data;
    //file1.close();
    fstream file2;
    file2.open(fname, ios::in); /// Open file in read mode
    if (!file2)
        cout << "File Not Found" << endl;
    while(file2.good())
    {

        file2>>temp>>data;
        if(searchOP==temp)
            break;


    }
    if(searchOP==temp)
        return stoi(data);
    else
    {
        cout<<"data not found "<<endl;
        return -1;
    }

}


void ReadWrite::add_additional_data(string s,string key)
{
    fstream f3;
    f3.open(fname,ios::in);
    string l1,l2;
    vector<string> tokens;

    int c1=0,flag=0;
    if (!f3)
        cout << "File Not Found" << endl;
    while(f3.good())
    {
        string temp="";
        getline(f3,l1);
        stringstream check(l1);
        while(getline(check,l2,' '))
        {
            if(c1%2)
            {
                temp+=" ";
                if(flag)
                {
                    l2=key;
                    flag=0;
                }

            }
            else
            {
                if(s==l2)
                    flag=1;

            }
            temp+=l2;
            if(c1%2)
                temp+="\0";
            c1++;
        }
        tokens.push_back(temp);

    }


    f3.close();
    f3.open(fname,ios::out);
    if (!f3)
        cout << "File Not Found" << endl;

    for(int i = 0; i < tokens.size(); i++)
        f3 << tokens[i] << '\n';
    f3.close();
}


/// Convert the key into corresponding index of the vector
int ReadWrite::keyToIndex(string key)
{
    if(getFname()=="info.txt")
        {
           if(key == "id")
            return 0;
        else if (key == "name")
            return 0;
        else if (key == "age")
            return 1;
        else if (key == "gender")
            return 2;
        else if (key == "occupation")
            return 3;
        else if (key =="email" )
            return 4;
        else if (key == "address")
            return 5;
        else if (key == "phone")
            return 6;
        else if (key == "username")
            return 7;
        }
        else if(getFname()=="Paitien_info.txt")
        {
            if(key == "username")
                return 0;
            else if(key == "percent")
                return 1;
            else if(key == "money")
                return 2;
            else if(key == "date")
                return 3;
            else if(key == "vaccinate")
                return 4;
        }
        else
        {
            if(key == "id")
            return 0;
        else if (key == "usertype")
            return 0;
        else if (key == "reqtype")
            return 1;
        else if (key == "update")
            return 2;
        //else if (key == "status")
            //return 3;
        else if (key == "date")
            return 3;

        }

}


/// 1 Argument display func to show all information from the file
void ReadWrite::display()
{
    read("");
    if (show.empty())
        cout << "The file is empty" << endl;
    for (auto i : show) /// Simply print the elements. Can be customized later
        cout << i << endl;
}


/// 2 Argument display func to show specific entry based on search ID
void ReadWrite::display(string searchID)
{
    read(searchID);
    if (show.empty())
        cout << searchID << " Not Found" << endl;
    //for (auto i : v1)
    cout << show[0] << endl;
}


/// Simply write the passed data at the end of the file
void ReadWrite::add(string data)
{
    file1.close();
    file1.open(fname, ios::app);
    if (file1)
    {
        //cout<<fname <<"inside add"<<endl;
        file1 << data << endl;
    }
    else
        cout<<"fail in add()"<<endl;
    file1.close();
}


/// Update any attribute of the person like name, age, etc.
/// If passed key and newData is "" then it deletes that person
void ReadWrite::update(string searchID, string key, string newData)
{
    file1.open(fname);
    string line;
    int lineNo = 0, index;
    if(key != "")
        index = keyToIndex(key);
    bool updated = false;
    v1.clear();
    while (getline(file1, line)) /// Iterate over the file line by line
    {
        if (line != searchID)
            v1.push_back(line); /// Push every data other than the searched ID
        else
        {
            if(key != "")
                v1.push_back(line);
            while (line != "") /// Iterate over the searched ID's scope
            {
                getline(file1, line);
                if(key == "" && newData == "")  /// This if block is used to
                {
                    updated = true;             /// ignore rest of the code
                    continue;                   /// to delete the person
                }
                if (index == lineNo) /// lineNo matches with key index so
                {
                    /// it is updating that line by pushing
                    updated = true;  /// new data to vector
                    v1.push_back(newData);
                }
                else
                    v1.push_back(line);
                lineNo++;
            }
        }
    }
    file1.close();
    if (updated)
    {
        /// Overwrite all the data from vector to file
        file1.open(fname, ios::out);
        for (auto i : v1)    ///  while overwriting the file after deleting or updating the last id
        {
            /// there remains an extra blank line in the file
            file1 << i << endl;  /// which changes the display order of the next line as a blank
        }                         ///  line is read in the beginning of next data reading
        file1.close();
    }
    else
        cout << searchID << " Not Found" << endl;
}


bool ReadWrite::onlyRead(string name, string pass)
{
    bool flag = false;
    file1.open(fname, ios::in);
    if (!file1)
    {
        cout << "File Not Found" << endl;
        return flag;
    }
    else
    {
        string line, line2;
        while (file1.good())
        {
            file1 >> line;
            file1 >> line2;
            if (line == name && line2 == pass)
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}


void ReadWrite::erase_data(string searchID)
{
    update(searchID, "", ""); /// Pass "" as parameters to achieve
    /// delete fuctionality with update
}
void ReadWrite::erase(string id,string reqtype,string up)
    {
        vector<string> n;
        string s;
        int line=0;
        bool flag=false;
        file1.open(fname,ios::in);
        while(file1.good())
        {
            getline(file1,s);

            if(s!="")
            {
                    line++;
            n.push_back(s);
            }

        }
        file1.close();
        file1.open(fname, ios::out);
        for(int i=0;i<=line;i++)
        {
            if(n[i]==id && n[i+2]==reqtype && n[i+3]==up) flag=true;
            if(!flag)
            file1<<n[i]<<endl;
            if(!(i%5) && i ) flag=false;
        }
        //cout<<"line"<<line<<endl;
    }
string ReadWrite::fname="";