#include "client.hpp"
#include <iostream>

using namespace std;

Client::Client(string_view name2)
{
	m_name = string(name2);
	cout << "Client '" << m_name << "' online.\n";
}

Client::~Client()
{
	cout << "Client '" << m_name << "' offline.\n";
}

shared_ptr<Zakaz> Client::MakeZakaz(int id)
{
	if (m_activeCount < m_limit)
	{
		m_zList[m_activeCount] = make_shared<Zakaz>(0); //Можно бы было сократить эту строчку в одну, но! Это заготовка для более крупного конструктора заказа
		m_zList[m_activeCount]->FormZakaz(id);
		m_activeCount++;
		return m_zList[m_activeCount - 1];
	}
	else
	{
		cout << "Client '" << m_name << "' tried to get more delivery than he given!\n";
		return nullptr;
	}
}