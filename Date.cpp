#include "Date.h"


Date::Date()
    {
        m=0;
        d=0;
        y=0;
    }
void Date::set_date(int day,int month,int year )
    {
        y=year;
        m=month;
        d=day;
    }
int  Date::get_month()
    {
        return m;
    }
int  Date::get_year()
    {
        return y;
    }
int  Date::get_day()
    {
        return d;
    }
void Date::save_current_date()
    {

        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);


         this->d=now->tm_mday;
         this->m=now->tm_mon + 1;
         this->y=now->tm_year + 1900;
    }
string Date::Convert_to_string()
    {
        string temp="";
        temp+=to_string(d)+"-"+to_string(m)+"-"+to_string(y);
        return temp;

    }
void Date::Save_from_string(string s)
    {
        string l2;
        stringstream check(s);
        int cnt=1;
        while(getline(check,l2,'-'))
        {
            if(cnt==1) this->d=stoi(l2);
            else if(cnt==2) this->m=stoi(l2);
            else if(cnt==3) this->y=stoi(l2);
            cnt++;
        }
    }
void Date::display()
{
    cout<<this->Convert_to_string()<<endl;
}
int Date::operator-(Date &dt2)
{
    long int n1 = this->y * 365 + this->d;
    for (int i = 0; i < this->m - 1; i++)
	    n1 += monthDays[i];
	n1 += countLeapYears(*this);

	long int n2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);
	return (n1 - n2);
}