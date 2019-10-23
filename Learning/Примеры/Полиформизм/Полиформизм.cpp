//Полиформизм - из одной переменной может быть множество разных функций.

#include "pch.h"
#include <iostream>

using namespace std;

class Enemy {
public:
	virtual void attack()= 0;     //Использование виртуальной функции          
};

class Ninja :public Enemy {
public:
	void attack() {
		cout << "Nunja! -" << endl;
	}
};

class Monster :public Enemy {
public:
	void attack() {
		cout << "Monster! - " << endl;
	}
};
/*class Enemy {
protected:
	int AttackPower;
public:
	void SetAttackPower(int a) {
		AttackPower = a;
	}
};

class Ninja :public Enemy {
public:
	void attack() {
		cout << "Nunja! -" << AttackPower << endl;
	}
};

class Monster :public Enemy {
public:
	void attack() {
		cout << "Monster! - " << AttackPower << endl;
	}
};*/

int main()
{
	Ninja n;
	Monster m;
	Enemy *e1 = &n;
	Enemy *e2 = &m;

	e1->attack();
	e2->attack();

	return 0;
}