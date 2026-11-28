#include "client.hpp"
#include <iostream>

using namespace std;

BaseClient::BaseClient()
{
	cout << "BaseClient constructor, no parameter\n";
}

BaseClient::BaseClient(std::string_view name)
	: m_name{ name }
{
	cout << "BaseClient constructor, with parameters\n";
	cout << "Client '" << m_name << "' online.\n";
}

BaseClient::BaseClient(const BaseClient& other)
	: m_activeCount{other.m_activeCount}
	, m_name{other.m_name}
{
	for (int i = 0; i < MAX_LIMIT; ++i)
	{
		m_zList[i] = other.m_zList[i];
	}
	cout << "BaseClient constructor, copy\n";
}

BaseClient::BaseClient(BaseClient&& other) noexcept
{
	m_activeCount = move(other.m_activeCount);
	other.m_activeCount = 0;
	m_name = move(other.m_name);
	for (int i = 0; i < MAX_LIMIT; ++i)
	{
		m_zList[i] = move(other.m_zList[i]);
	}
	cout << "BaseClient constructor, move\n";
}

BaseClient& BaseClient::operator=(const BaseClient& other)
{
	if (this == &other)
	{
		return *this;
	}
	m_activeCount = other.m_activeCount;
	m_name = other.m_name;
	for (int i = 0; i < MAX_LIMIT; ++i)
	{
		m_zList[i] = other.m_zList[i];
	}
	cout << "BaseClient operator, copy\n";
	return *this;
}

BaseClient& BaseClient:: operator=(BaseClient&& other) noexcept
{
	if (this == &other)
	{
		return *this;
	}
	m_activeCount = move(other.m_activeCount);
	other.m_activeCount = 0;
	m_name = move(other.m_name);
	for (int i = 0; i < MAX_LIMIT; ++i)
	{
		m_zList[i] = move(other.m_zList[i]);
	}
	cout << "BaseClient operator, move\n";
	return *this;
}

BaseClient::~BaseClient()
{
	cout << "BaseClient destructor\n";
	cout << "Client '" << m_name << "' offline.\n";
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


FClient::FClient()
	: BaseClient{}
{
	cout << "FClient constructor, no parameter\n";
}
FClient::FClient(std::string_view name)
	: BaseClient{ name }
{
	cout << "FClient constructor, with parameters\n";
}
FClient::FClient(const FClient& other)
	: BaseClient{ other }
{
	cout << "FClient constructor, copy\n";
}
FClient::FClient(FClient&& other) noexcept
	: BaseClient{ move(other) }
{
	cout << "FClient constructor, move\n";
}
FClient& FClient::operator=(const FClient& other)
{
	BaseClient::operator=(other);
	cout << "FClient operator, copy\n";
	return *this;
}
FClient& FClient::operator=(FClient&& other) noexcept
{
	BaseClient::operator=(move(other));
	cout << "FClient operator, move\n";
	return *this;
}
FClient::~FClient()
{
	cout << "FClient destructor\n";
}

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