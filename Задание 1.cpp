#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int hours;
    double rate, bonuspercent, totalsalary;
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> rate;
    cout << "Введите процент премии: ";
    cin >> bonuspercent;
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    totalsalary = basesalary + bonus;
    cout << "\nРезультаты расчета:" << endl;
    cout << "Основная зарплата: " << basesalary << " руб." << endl;
    cout << "Премия: " << bonus << " руб." << endl;
    cout << "Общая сумма: " << totalsalary << " руб." << endl;
    return 0;
}