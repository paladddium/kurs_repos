#include "client.hpp"
#include "zakaz.hpp"

#include <iostream>
using namespace std;

Client::Client(string_view Name2)
{
	Name = string(Name2);
	zList = new Zakaz[2];
	cout << "Client '" << Name << "' online.\n";
}

Client::~Client()
{
	delete[] zList;
	cout << "Client '" << Name << "' offline.\n";
}

Zakaz* Client::MakeZakaz(int Id)
{
	if (activeCount < Limit)
	{
		zList[activeCount].FormZakaz(Id);
		activeCount += 1;
		return &zList[activeCount - 1];
	}
	else
	{
		cout << "Client '" << Name << "' tried to get more delivery than he given!\n";
		return nullptr;
	}
}