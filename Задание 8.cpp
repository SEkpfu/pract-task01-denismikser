#include <iostream>
using namespace std;
double totalsalary(int hours, double rate, double bonuspercent)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
double incometax(double totalsalary)
{
    return totalsalary * 0.13;
}
double netsalary(double totalsalary)
{
    double tax = incometax(totalsalary);
    return totalsalary - tax;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double bonuspercent = 15.0;
    cout << "Введите количество работников: ";
    cin >> n;
    if (n <= 0) {
        cout << "Ошибка: количество работников должно быть положительным числом!" << endl;
        return 1;
    }
    int* hours = new int[n];
    double* rate = new double[n];
    double* salary = new double[n];
    double* tax = new double[n];
    double* netSalary = new double[n];
    cout << "\nВведите данные о " << n << " работниках:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nРаботник №" << i + 1 << endl;
        cout << "Количество отработанных часов: ";
        cin >> hours[i];
        cout << "Ставка почасовой оплаты (руб./час): ";
        cin >> rate[i];
    }
    for (int i = 0; i < n; i++) {
        salary[i] = totalsalary(hours[i], rate[i], bonuspercent);
        tax[i] = incometax(salary[i]);
        netSalary[i] = netsalary(salary[i]);
    }
    double minsalary = salary[0];
    int minindex = 0;
    for (int i = 1; i < n; i++) {
        if (salary[i] < minsalary) {
            minsalary = salary[i];
            minindex = i;
        }
    }
    double maxsalary = salary[0];
    int maxindex = 0;
    for (int i = 1; i < n; i++) {
        if (salary[i] > maxsalary) {
            maxsalary = salary[i];
            maxindex = i;
        }
    }
    int counthighsalary = 0;
    int* highsalaryworkers = new int[n];
    for (int i = 0; i < n; i++) {
        if (netSalary[i] > 50000) {
            highsalaryworkers[counthighsalary] = i;
            counthighsalary++;
        }
    }
    double totaltax = 0;
    for (int i = 0; i < n; i++) {
        totaltax += tax[i];
    }
    cout << "\n№  | Часы | Ставка | Зарплата | Налог  | На руки" << endl;
    cout << "---+------+--------+----------+--------+---------" << endl;
    for (int i = 0; i < n; i++) {
        printf("%-2d | %-4d | %-6.0f | %-8.0f | %-6.0f | %-8.0f\n",
            i + 1, hours[i], rate[i], salary[i], tax[i], netSalary[i]);
    }
    cout << "\n1. Меньше всех получил работник №" << minindex + 1
        << " (" << minsalary << " руб.)" << endl;
    cout << "2. Максимальная зарплата: " << maxsalary << " руб. "
        << "(работник №" << maxindex + 1 << ")" << endl;
    cout << "3. Работников с зарплатой на руки более 50000 руб.: " << counthighsalary << endl;
    if (counthighsalary > 0) {
        cout << "   Номера работников: ";
        for (int i = 0; i < counthighsalary; i++) {
            cout << highsalaryworkers[i] + 1;
            if (i < counthighsalary - 1) cout << ", ";
        }
        cout << endl;
    }
    else {
        cout << "   Таких работников нет" << endl;
    }
    cout << "4. Общая сумма налога, уплаченного бригадой: "
        << totaltax << " руб." << endl;
    return 0;
}