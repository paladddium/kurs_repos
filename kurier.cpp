#include "kurier.hpp"
#include "zakaz.hpp"
#include <memory>

#include <iostream>
using namespace std;

Kurier::Kurier(std::string_view name)
{
	m_name = string(name);
	cout << "Courier '" << m_name << "' online.\n";
}

Kurier::~Kurier()
{
	cout << "Courier '" << m_name << "' offline.\n";
}

void Kurier::getZakaz(shared_ptr<Zakaz> z)
{
	if (m_activeCount < m_limit)
	{
		m_zList[m_activeCount] = z;
		cout << "Courier '" << m_name << "' got delivery #" << z->getID() << "\n";
		m_activeCount++;
	}
	else
	{
		cout << "Courier'" << m_name << "''tried to get more delivery than he given!\n";
	}
}