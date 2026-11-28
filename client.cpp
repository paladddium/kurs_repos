#include "client.hpp"
#include <iostream>

using namespace std;

BaseClient::BaseClient(std::string_view name)
	: m_name{name}
{
	cout << "Client '" << m_name << "' online.\n";
}

bool BaseClient::CheckAbility() const
{
	return (m_activeCount < MAX_LIMIT);
}

int BaseClient::GetActiveCount() const
{
	return m_activeCount;
}

std::string_view BaseClient::GetName() const
{
	return m_name;
}

void BaseClient::AddActiveCount()
{
	if (CheckAbility())
	{
		m_activeCount++;
	}
}

BaseClient::~BaseClient()
{
	cout << "Client '" << m_name << "' offline.\n";
}


FClient::FClient(std::string_view name) : BaseClient{ name } {}

std::shared_ptr<Zakaz> FClient::MakeZakaz(int id)
{
	if (CheckAbility())
	{
		int x = GetActiveCount();
		m_zList[x] = make_shared<Zakaz>(0);
		m_zList[x]->FormZakaz(id);
		AddActiveCount();
		return m_zList[x];
	}
	else
	{
		cout << "Client '" << GetName() << "' tried to get more delivery than he given!\n";
		return nullptr;
	}
}

UClient::UClient(std::string_view name) : BaseClient{ name } {}

std::shared_ptr<Zakaz> UClient::MakeZakaz(int id)
{
	if (CheckAbility())
	{
		int x = GetActiveCount();
		m_zList[x] = make_shared<Zakaz>(0);
		m_zList[x]->FormZakaz(id);
		AddActiveCount();
		return m_zList[x];
	}
	else
	{
		cout << "Client '" << GetName() << "' tried to get more delivery than he given!\n";
		return nullptr;
	}
}