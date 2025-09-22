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
    int hours1, hours2, hours3, hours4, hours5;
    double rate1, rate2, rate3, rate4, rate5, bonuspercent = 15.0;
    cout << "Данные для первого работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours1;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate1;
    cout << "\nДанные для второго работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours2;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate2;
    cout << "\nДанные для третьего работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours3;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate3;
    cout << "\nДанные для четвертого работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours4;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate4;
    cout << "\nДанные для пятого работника" << endl;
    cout << "Количество отработанных часов: ";
    cin >> hours5;
    cout << "Ставка почасовой оплаты (руб./час): ";
    cin >> rate5;
    double salary1 = totalsalary(hours1, rate1, bonuspercent);
    double salary2 = totalsalary(hours2, rate2, bonuspercent);
    double salary3 = totalsalary(hours3, rate3, bonuspercent);
    double salary4 = totalsalary(hours4, rate4, bonuspercent);
    double salary5 = totalsalary(hours5, rate5, bonuspercent);
    double totalsum = salary1 + salary2 + salary3 + salary4 + salary5;
    double averagesalary = totalsum / 5;
    cout << "\nЗарплата первого работника: " << salary1 << " руб." << endl;
    cout << "Зарплата второго работника: " << salary2 << " руб." << endl;
    cout << "Зарплата третьего работника: " << salary3 << " руб." << endl;
    cout << "Зарплата четвертого работника: " << salary4 << " руб." << endl;
    cout << "Зарплата пятого работника: " << salary5 << " руб." << endl;
    cout << "\nОбщая сумма, заработанная бригадой: " << totalsum << " руб." << endl;
    cout << "Средняя зарплата в бригаде: " << averagesalary << " руб." << endl;
    return 0;
}