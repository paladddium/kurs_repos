#include "client.hpp"
#include <iostream>

using namespace std;

Client::Client(string_view name2)
{
	m_name = string(name2);
	for (int i = 0; i < m_limit; i++)
	{
		m_zList[i] = make_unique<Zakaz>(0);
	}
	cout << "Client '" << m_name << "' online.\n";
}

Client::~Client()
{
	cout << "Client '" << m_name << "' offline.\n";
}

Zakaz* Client::MakeZakaz(int id)
{
	if (m_activeCount < m_limit)
	{
		m_zList[m_activeCount]->FormZakaz(id);
		m_activeCount++;
		return m_zList[m_activeCount - 1].get();
	}
	else
	{
		cout << "Client '" << m_name << "' tried to get more delivery than he given!\n";
		return nullptr;
	}
}