#include "pch.h"
#include "Bank_acc.h"

using namespace std;

namespace bank_space {
	
	Bank_acc::Bank_acc(string name, double money, double rate, int time)
	{
		set_name(name);
		set(money, rate, time);
		show();
	}
	double Bank_acc::result()
	{
		double res = money;
		int i;
		for (i = 0; i <= time; i++) {
			res = res * (1 + rate / 100);
		}
		return res;
	}
	void Bank_acc::set(double money,double rate,int time)
	{
		this->money = money;
		this->rate = rate;
		this->time = time;
	}
	void Bank_acc::set_name(string n)
	{
		name = n;
	}
	void Bank_acc::show()
	{
		cout << name;
		cout << ": " << money << ": " << rate << ": " << time;
		cout << ": " << result() << endl;
	}
	Bank_acc::~Bank_acc()
	{
	}
}