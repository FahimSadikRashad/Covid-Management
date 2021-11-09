#include "data_filter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

void data_filter::read(string category)  ///over ridden function
{
    /// defining position of line in "pos"to check the related attribute with the category
    //if(category == "student" or category == "Doctor" or category == "Teacher" or
    //category == "Engineer" or category == "Businessman" or category == "Labourer")
    if(category=="profession")
    {
        cout<<"\t\t\t  ENTER PROFESSION: ",category.clear(),cin>>category,pos = 5;
        if(!catagory_data(category))
            return;
        else
            setFname("info.txt");

    } /// occupation
    else if(category == "male" or category == "female")
        pos = 4;  /// gender
    else if(category[0] >= '1' and category[0] <= '9')
        pos = 3; /// age
    else if(category == "username")
        cout<<"\t\t\t  ENTER USERNAME: ",cin>>category,pos =9;
    else
        pos = 7; /// address

    ReadWrite::show1.clear();
    string s1 = "ID";
    s1+= "    ";
    string s2 = "NAME";
    s2.resize(18);
    s2+= "    ";
    string s21 = "AGE";
    s21.resize(3);
    s21+= "    ";
    string s3 = "GENDER";
    s3.resize(6);
    s3+= "    ";
    string s4 = "OCCUPATION";
    s4.resize(12);
    s4+= "    ";
    string s5 = "EMAIL ADDRESS";
    s5.resize(10);
    s5+= "    ";
    string s6 = "LOCATION";
    s6.resize(11);
    s6+= "    ";
    string s7 = "PHONE_NO";
    s7.resize(22);
    s7+= "    ";
    string s8 = "USERNAME";
    s8.resize(10);
    string s = s1+s2+s21+s3+s4+s5+s6+s7+s8;
    show1.push_back(s);
    bool flag = false;
    file2.open(fname, ios::in); /// Open file in read mode
    if (!file2)
        cout << "--File Not Found--" << endl;
    else
    {
        string line, temp1 = "";
        int cnt = 0;

        while (file2.good()) /// Iterate over the file until any error occurs
        {
            getline(file2, line); /// storing the data of a person into a single string
            int length = line.size();
            if(cnt == 1)
                line.resize(18);
            else if(cnt == 2)
                line.resize(3);
            else if(cnt == 3)
                line.resize(6);
            else if(cnt == 4)
                line.resize(12);
            else if(cnt == 5)
                line.resize(10);
            else if(cnt == 7)
                line.resize(22);
            temp1 += line;
            temp1 += "    ";
            cnt++;
            line.resize(length);
            if(cnt == pos and line == category)
                flag = true;
            if(cnt == pos and pos ==3)
            {
                int age, test, u, l,ct=0;

                age=stoi(line);
                //test=stoi(category);
                //vector <string> tokens;

                //stringstream  check1;
                stringstream check1(category);

                string intermediate,key("just");

                // Tokenizing w.r.t. space ' '
                while(getline(check1, intermediate, '-'))
                {
                    if(ct==0)
                        l=stoi(intermediate);
                    else
                        u=stoi(intermediate);
                    ct++;
                    //intermediate=key;
                    //tokens.push_back(intermediate);
                }

                //u = test+5;
                //l = test-5;
                if( age >= l and age <= u)
                    flag = true;
            }

            if(flag == true and cnt == 10)
            {
                show1.push_back(temp1); /// only pushing the filtered data
                flag = false;
                temp1 = "";
                cnt = 0;
            }
            if(cnt == 10)
            {
                flag = false;
                temp1 = "";
                cnt = 0;
            }
            //cout<<cnt<<" "<<temp1<<endl;
        }

    }

    file2.close();

}

bool data_filter::catagory_data(string s)
{
    setFname("Catagory.txt");
    fstream f;
    f.open(fname,ios::in);
    if(!f)
        cout<<fname<<" can't open"<<endl;
    else
    {
        string line;
        while(f.good())
        {
            getline(f,line);
            if(line==s)
                return true;
        }
        return false;
    }

}

void data_filter::display()     ///over ridden function
{
    if (show1.empty())
        cout << "\t\t  --There is no relevant data for that category--" << endl;

    for (auto i : show1)          /// Simply printing the elements for the filtered data
        cout << i << endl;
}
