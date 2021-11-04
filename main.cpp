#include "menu.cpp"
using namespace std;

int countLeapYears(Date &d)
{
	int years = d.y;
	if (d.m <= 2)
		years--;
	return years / 4
		- years / 100
		+ years / 400;
}

int main()
{
	Menu m;
	//Menu::animation2(2, 15, 15, 0);
	//Patient::check_symptoms();
    return 0;
}
