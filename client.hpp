#pragma once
#include <string>
#include <string_view>

class Zakaz;

class Client
{
	private:
		static const char Limit = 2;
		char activeCount = 0;
		Zakaz* zList = nullptr;
		std::string Name;

	public:
		Client(std::string_view);
		~Client();
		Zakaz* MakeZakaz(int);
};