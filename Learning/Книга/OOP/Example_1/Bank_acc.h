#pragma once
#include "pch.h"

namespace bank_space {

	class Bank_acc
	{
	private:
		string name;
		double money;
		double rate;
		int time;
	public:
		Bank_acc(string name, double money, double rate, int time);
		double result();
		void set(double money,double rate,int time);
 		void set_name(string n);
		void show();
		~Bank_acc();
	};


}

