#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<sstream>

class Patient : public Person
{
private :
    static int Patient_number;
    static int  percent;
    static int money;
    static  int  vaccinate;
    static Date d1;
public :
    void static increment();
	void static check_symptoms();
	void static save_date();
	void static money_spent();
	void static vaccine();
	void static display();
	void  save_information_on_paitent(string );
	void  save_req(string req_type, string update_type, string ID,string user_type);
};
#endif

