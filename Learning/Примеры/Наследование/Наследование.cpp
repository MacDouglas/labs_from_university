//Класс может быть наследован от множества классов, с помощью указания базовых классов
//разделенных запятыми. Пример: class Doughter:public Mother,public Father

//Класс наследует все базовые методы, кроме: Конструкторов\Деструкторов, Перегруженных операторов
//Дружественных (friend) функций

#include "pch.h"
#include <iostream>

using namespace std;

class Mother {
public:
	Mother(){
		cout << "Mother ctor" << endl;
	}
	~Mother() {
		cout << "Mother dtor" << endl;
	}
	void SayHi() {
		cout << "Hi" << endl;
	}
private:
	int var = 0;
protected:          //Может быть доступна только в производном классе
	int someVar = 0;
};

class Doughter : public Mother {
public:
	Doughter() {
		cout << "Dougther ctor" << endl;
	}
	~Doughter() {
		cout << "Doughter dtor" << endl;
	}
};

int main()
{
	Mother m;	
	//Doughter d;
	//d.SayHi();
}


