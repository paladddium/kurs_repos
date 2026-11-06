#pragma once
#include <string>
#include <string_view>

class Zakaz;

class Kurier
{
	private:
		static const char Limit = 2;
		char activeCount = 0;
		Zakaz** zList = nullptr;
		std::string Name;

	public:
		Kurier(std::string_view);
		~Kurier();
		void getZakaz(Zakaz*);
};