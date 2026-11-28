#include "zakaz.hpp"

#include <iostream>
using namespace std;

Zakaz::Zakaz(int id)
{
	m_id = id;
	cout << "Delivery created #" << m_id << "\n";
}

Zakaz::~Zakaz()
{
	cout << "Delivery #" << m_id << " closed\n";
}

void Zakaz::FormZakaz(int id)
{
	m_id = id;
	cout << "Delivery described #" << m_id << "\n";
}

void Zakaz::aliveStatus()
{
	cout << "Delivery #" << m_id << " is alive!\n";
}

int Zakaz::getID()
{
	return m_id;
}