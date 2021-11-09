#include "password_in.h"
using namespace std;


string password_in::getPass()
{
    fflush(stdin);
    char a;
    //for(int j=0;;)
    //{
        for(int i=0;;)
        {
            a = getch();
            if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            {
                pas += a;
                ++i;
                cout<<"*";
            }
            if(a=='\b'&&i>=1)
            {
                cout<<"\b \b";
                i--;
            }
            if(a=='\r')
            {
                break;
            }
            passLen = i;
        }
        
        return pas;
        //if(checkPass())
        //    break;
    //}
}
void password_in::showPass()
{
    cout<<"\nYou entered : "<<pas;
}
int password_in::checkPass()
{
    if(passLen<=5)
    {
        cout<<"\n\n\n\t\tPassword should be atleast 6 digits long\n";
        return 0;
    }
    return 1;
}
void password_in::showLength()
{
    cout<<"\nPassword length: "<<passLen<<endl;
}


string password_in::pas = "";
int password_in::passLen;

