#include "client.hpp"
#include "zakaz.hpp"
#include "kurier.hpp"
#include <memory>

#include <iostream>
using namespace std;

int main()
{
	{
		unique_ptr <Kurier> ptr_kur1 = make_unique<Kurier>("Petr");
		// Специально сделано так, чтобы клиент и заказы были уничтожены до конца программы
		{
			cout << "Demonstration Software\n";
			unique_ptr<Client> ptr_cl1 = make_unique<Client>("Vlad");
			shared_ptr<Zakaz> z1 = ptr_cl1->MakeZakaz(4); // В демонстрации подразумевается, что лимит активных заказов клиента равен 2. Первый-второй заказы ГАРАНТИРОВАНО оформляются
			shared_ptr<Zakaz> z2 = ptr_cl1->MakeZakaz(5);

			cout << "Zakaz #" << z2->getID() << " has " << z2.use_count() << " owners\n";

			{
				cout << "Making zakaz #" << z2->getID() << " copy because its VIP client maybe...\n";
				shared_ptr<Zakaz> z2_save = z2;
				cout << "Zakaz #" << z2->getID() << " has " << z2.use_count() << " owners\n";
			}
			cout << "Zakaz #" << z2->getID() << " has " << z2.use_count() << " owners\n";
			// Специально сделано так, чтобы курьер удалился раньше чем клиент с заказами
			{
				if (z1 != nullptr)
				{
					ptr_kur1->getZakaz(z1);
					ptr_kur1->checkZakaz();
				}
				if (z2 != nullptr)
				{
					ptr_kur1->getZakaz(z2);
					ptr_kur1->checkZakaz();
				}
			}
			unique_ptr<Client> ptr_cl2 = move(ptr_cl1);
			if (ptr_cl1 == nullptr)
			{
				cout << "Client`s data was moved due to some reasons\n";
			}
			shared_ptr<Zakaz> z3 = ptr_cl2->MakeZakaz(6); // ТОЛЬКО в демонстрации, мы НАРУШАЕМ границу и сознательно не передаем заказ курьеру, т.к. заказ НЕВОЗМОЖНО оформить из-за лимитов у клиента
			if (z3 == nullptr)
			{
				//Ничего не делаем, т.к. заказ не создан
			}
			z1->aliveStatus();
			z2->aliveStatus();
		}
		ptr_kur1->checkZakaz();
	}
	cin.get();
}