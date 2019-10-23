#include "pch.h"


using namespace std;

class BirthDay
{
public:
	BirthDay(int m, int d, int y) :month(m), day(d), year(y) {}

	void PrintDate() {
		cout << month << "\t" << day << "\t" << year << endl;
	}

private:
	int month;
	int day;
	int year;
};

int main()
{
	BirthDay bd(2, 15, 1999);
	Person p("Elias", bd);
	p.PrintInfo();

}
