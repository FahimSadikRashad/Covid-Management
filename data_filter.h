#ifndef DATA_FILTER_H
#define DATA_FILTER_H
#include "ReadWrite.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

using namespace std;

class data_filter :  public ReadWrite
{
  int pos;
    fstream file2;
    string fname = "info.txt", temp1 = "";
public:
  void read(string category);  ///over ridden function

  void display(); ///over ridden function
  ~data_filter(){};
};

#endif
