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
       if(category == "Student" or category == "Doctor" or category == "Teacher" or
        category == "Engineer" or category == "Businessman" or category == "Labourer") pos = 5; /// occupation
       else if(category == "Male" or category == "Female") pos = 4;  /// gender
       else if(category[0] >= '1' and category[0] <= '9') pos = 3; /// age
       else pos = 6; /// address

       ReadWrite::show.clear();
        bool flag = false;
        file2.open(fname, ios::in); /// Open file in read mode
        if (!file2)
            cout << "File Not Found" << endl;
        else
        {
            string line, temp1 = "";
            int cnt = 0;

            while (file2.good()) /// Iterate over the file until any error occurs
            {
                getline(file2, line); /// storing the data of a person into a single string
                int length = line.size();
                if(cnt == 1) line.resize(18);
                else if(cnt == 3) line.resize(6);
                else if(cnt == 4) line.resize(11);
                else if(cnt == 5) line.resize(10);
                temp1 += line;
                temp1 += "    ";
                cnt++;
                line.resize(length);
                if(cnt == pos and line == category) flag = true;
                if(cnt == pos and pos ==3)
                {
                  //stringstream s1(line);
                  //stringstream s2(category);
                  int age, test, u, l;
                  //s1 >> age;
                 // s2 >> test;
                 age=stoi(line);

                  u = test+5;
                  l = test-5;
                  if( age >= l and age <= u) flag = true;
                }

                if(flag == true and cnt == 9)
                {
                  show.push_back(temp1); /// only pushing the filtered data
                  flag = false;
                  temp1 = "";
                  cnt = 0;
                }
                if(cnt == 9)
                {
                  flag = false;
                  temp1 = "";
                  cnt = 0;
                }
            }

         }

    file2.close();

  }


void data_filter::display()     ///over ridden function
    {
        if (show.empty())
            cout << "There is no relevant data for that category" << endl;

        for (auto i : show)          /// Simply printing the elements for the filtered data
            cout << i << endl;
    }
