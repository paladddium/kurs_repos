#include "client.hpp"
#include "zakaz.hpp"
#include "kurier.hpp"

#include <iostream>
using namespace std;

int main()
{
	// Специально сделано так, чтобы клиент и заказы были уничтожены до конца программы
	{
		cout << "Demonstration Software\n";
		Client client1("Vlad");
		Zakaz* z1 = client1.MakeZakaz(4); // В демонстрации подразумевается, что лимит активных заказов клиента равен 2. Первый-второй заказы ГАРАНТИРОВАНО оформляются
		Zakaz* z2 = client1.MakeZakaz(5);
		// Специально сделано так, чтобы курьер удалился раньше чем клиент с заказами
		{
			Kurier kurier1("Petr");
			if (z1 != nullptr)
			{
				kurier1.getZakaz(z1);
			}
			if (z2 != nullptr)
			{
				kurier1.getZakaz(z2);
			}
		}
		Zakaz* z3 = client1.MakeZakaz(6); // ТОЛЬКО в демонстрации, мы НАРУШАЕМ границу и сознательно не передаем заказ курьеру, т.к. заказ НЕВОЗМОЖНО оформить из-за лимитов у клиента
		if (z3 == nullptr)
		{
			//Ничего не делаем, т.к. заказ не создан
		}
		z1->aliveStatus();
		z2->aliveStatus();
	}
	cin.get();
}