#include "kurier.hpp"
#include "zakaz.hpp"
#include <memory>

#include <iostream>
using namespace std;

Kurier::Kurier(string_view name)
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
		cout << "Courier'" << m_name << "'tried to get more delivery than he given!\n";
	}
}

void Kurier::checkZakaz() const
{
	shared_ptr<Zakaz> ptr_temp;
	for (int i = 0; i < m_limit; i++)
	{
		if (ptr_temp = m_zList[i].lock())
		{
			cout << "Zakaz #" << ptr_temp->getID() << " is handled\n";
		}
		else
		{
			cout << i << "th Zakaz was lost\n";
		}
	}
}