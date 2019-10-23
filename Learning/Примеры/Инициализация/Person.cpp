#include "pch.h"
#include "Person.h"



Person::Person(string n, BirthDay b) :name(n), bd(b) {}

void Person::PrintInfo() {
cout << name << endl;
bd.PrintDate();
};
