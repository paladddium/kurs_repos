#pragma once

class Zakaz
{
	private:
		int m_id;

	public:
		Zakaz(int id = 0);
		~Zakaz();
		void FormZakaz(int);
		void aliveStatus();
		int getID();
};