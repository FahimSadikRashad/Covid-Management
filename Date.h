#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>
#include<time.h>

class Date
{
private :
    int m,d,y;
    const int monthDays[12]
	= { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31 };

public:
    friend  int countLeapYears(Date &d);
	Date();
    
	void set_date(int day,int month,int year );
    
	int get_month();
    
	int  get_year();
    
	int  get_day();
    
	void save_current_date();
     
	string Convert_to_string();

    
	void Save_from_string(string s);
    
	void display();
    
	int operator-(Date &dt2);
    
};
#endif
