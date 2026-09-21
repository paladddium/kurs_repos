// Лабораторная работа № 1. Вариант 72.
// Выполнил: Губин Л. А., группа ПИ-52.
#include <iostream>
using namespace std;

// ===== Расчётные функции варианта =====
// Перевод дней в часы
double daysToHours(double d) {
	return d*24;
}

// Перевод часов в минуты
double hoursToMinutes(double h) {
	return h * 60;
}

// Перевод дней в часы
double daysToHours(double d) {
	return d * 24;
}

// ===== Главная функция: меню =====
int main() {
	int choice;
	double x;
	do {
		cout << "\n--- Программа расчётов. Вариант 72 ---\n";
		cout << "1. Дни ↔ часы\n";
		cout << "2. Часы ↔ минуты\n";
		cout << "3. Минуты ↔ дни\n";
		cout << "0. Выход\n";
		cout << "Выберите пункт: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите количество дней: ";
			cin >> x;
			cout << "В часах = " << daysToHours(x) << "\n";
			break;
		case 2:
			cout << "Введите количество часов: ";
			cin >> x;
			cout << "В минутах = " << hoursToMinutes(x) << "\n";
			break;
		case 3:
			cout << "Введите количество минут: ";
			cin >> x;
			cout << "В днях = " << minutesToDays(x) << "\n";
			break;
		case 0:
			cout << "Работа завершена.\n";
			break;
		default:
			cout << "Такого пункта нет.\n";
		}
	} while (choice != 0);
	return 0;
}