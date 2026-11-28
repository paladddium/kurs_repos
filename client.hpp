#pragma once
#include <string>
#include <string_view>
#include <memory>
#include "Zakaz.hpp"

class Client
{
	private:
		static constexpr int m_limit = 2;
		int m_activeCount = 0;
		std::shared_ptr<Zakaz> m_zList[m_limit];
		std::string m_name;

	public:
		Client(std::string_view);
		~Client();
		std::shared_ptr<Zakaz> MakeZakaz(int);
};