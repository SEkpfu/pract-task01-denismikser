#include <iostream>
using namespace std;
void allsalary(int hours, double rate, double bonuspercent, double& totalsalary, double& tax, double& netsalary)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    totalsalary = basesalary + bonus;
    tax = totalsalary * 0.13;
    netsalary = totalsalary - tax;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int hours;
    double rate, bonuspercent, totalsalary, tax, netsalary;
    cout << "Введите количество отработанных часов: ";
    cin >> hours;
    cout << "Введите ставку почасовой оплаты (руб./час): ";
    cin >> rate;
    cout << "Введите процент премии: ";
    cin >> bonuspercent;
    allsalary(hours, rate, bonuspercent, totalsalary, tax, netsalary);
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    cout << "\nОсновная зарплата: " << basesalary << " руб." << endl;
    cout << "Премия: " << bonus << " руб." << endl;
    cout << "Общая начисленная сумма: " << totalsalary << " руб." << endl;
    cout << "Подоходный налог (13%): " << tax << " руб." << endl;
    cout << "Сумма к выдаче: " << netsalary << " руб." << endl;
    return 0;
}