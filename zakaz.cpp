#include "zakaz.hpp"

#include <iostream>
using namespace std;

Zakaz::Zakaz(int Id2)
{
	Id = Id2;
	cout << "Delivery created #" << Id << "\n";
}

Zakaz::~Zakaz()
{
	cout << "Delivery #" << Id << " closed\n";
}

void Zakaz::FormZakaz(int Id2)
{
	Id = Id2;
	cout << "Delivery described #" << Id << "\n";
}

void Zakaz::aliveStatus()
{
	cout << "Delivery #" << Id << " is alive!\n";
}

int Zakaz::getID()
{
	return Id;
}