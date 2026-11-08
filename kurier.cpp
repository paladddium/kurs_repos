#include "kurier.hpp"
#include "zakaz.hpp"

#include <iostream>
using namespace std;

Kurier::Kurier(std::string_view Name2)
{
	Name = string(Name2);
	zList = new Zakaz*[2];
	cout << "Courier '" << Name << "' online.\n";
}

Kurier::~Kurier()
{
	delete[] zList;
	cout << "Courier '" << Name << "' offline.\n";
}

void Kurier::getZakaz(Zakaz* z)
{
	if (activeCount < Limit)
	{
		zList[activeCount] = z;
		cout << "Courier '" << Name << "' got delivery #" << z->getID() << "\n";
		activeCount += 1;
	}
	else
	{
		cout << "Courier'" << Name << "''tried to get more delivery than he given!\n";
	}
}