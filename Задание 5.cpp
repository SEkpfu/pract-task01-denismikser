#include <iostream>
using namespace std;
double totalsalary(int hours, double rate, double bonuspercent)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int hours1, hours2;
    double rate1, bonuspercent1, rate2, bonuspercent2;
    cout << "Данные первого работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours1;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate1;
    cout << "Процент премии: ";
    cin >> bonuspercent1;
    cout << "\nДанные второго работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours2;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate2;
    cout << "Процент премии: ";
    cin >> bonuspercent2;
    double salary1 = totalsalary(hours1, rate1, bonuspercent1);
    double salary2 = totalsalary(hours2, rate2, bonuspercent2);
    double totalsalary = salary1 + salary2;
    int higherearner;
    if (salary1 > salary2)
    {
        higherearner = 1;
    }
    else if (salary2 > salary1)
    {
        higherearner = 2;
    }
    else
    {
        higherearner = 0;
    }
    cout << "\nЗарплата первого работника: " << salary1 << " руб." << endl;
    cout << "Зарплата второго работника: " << salary2 << " руб." << endl;
    cout << "Общая сумма: " << totalsalary << " руб." << endl;
    if (higherearner == 0) {
        cout << "Оба работника заработали одинаковую сумму" << endl;
    }
    else
    {
        cout << "Больше заработал работник №" << higherearner << endl;
    }
    return 0;
}