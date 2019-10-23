#pragma once

class Person {
public:
	Person(string n, BirthDay b) :name(n), bd(b) {}
	void PrintInfo();
private:
	string name;
	BirthDay bd;
};


