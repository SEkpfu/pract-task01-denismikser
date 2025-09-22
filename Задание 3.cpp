#include <iostream>
using namespace std;
void inputemployeedata(int& hours, double& rate, double& bonuspercent)
{
    cout << "Введите данные о работнике:" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate;
    cout << "Процент премии: ";
    cin >> bonuspercent;
}
double totalsalary(int hours, double rate, double bonuspercent)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
double incometax(double totalSalary)
{
    return totalSalary * 0.13;
}
double netsalary(double salary)
{
    double tax = incometax(salary);
    return salary - tax;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int hours;
    double rate, bonuspercent;
    inputemployeedata(hours, rate, bonuspercent);
    double salary = totalsalary(hours, rate, bonuspercent);
    double tax = incometax(salary);
    double finalsalary = netsalary(salary);
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    cout << "\nОсновная зарплата: " << basesalary << " руб." << endl;
    cout << "Премия: " << bonus << " руб." << endl;
    cout << "Общая начисленная сумма: " << salary << " руб." << endl;
    cout << "Подоходный налог (13%): " << tax << " руб." << endl;
    cout << "Сумма к выдаче: " << finalsalary << " руб." << endl;
    return 0;
}