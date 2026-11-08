#pragma once

class Zakaz
{
	private:
		int Id;

	public:
		Zakaz(int Id2 = 0);
		~Zakaz();
		void FormZakaz(int);
		void aliveStatus();
		int getID();
};