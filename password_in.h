#ifndef PASSWORD_IN_H
#define PASSWORD_IN_H
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class password_in
{
protected:
    static string pas;
    static int passLen;

public:
    static string getPass();

    static void showPass();
    static int checkPass();

    static void showLength();

};


#endif // PASSWORD_IN_H