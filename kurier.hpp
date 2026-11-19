#pragma once
#include <string>
#include <string_view>
#include <memory>
#include "Zakaz.hpp"

class Kurier
{
	private:
		static constexpr int m_limit = 2;
		int m_activeCount = 0;
		std::weak_ptr<Zakaz> m_zList[m_limit];
		std::string m_name;

	public:
		Kurier(std::string_view);
		~Kurier();
		void getZakaz(std::shared_ptr<Zakaz>);
		void checkZakaz() const;
};