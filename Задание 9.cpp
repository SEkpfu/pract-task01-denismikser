#include <iostream>
using namespace std;
double totalSalary(int hours, double rate, double bonuspercent)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
double incometax(double totalsalary)
{
    return totalsalary * 0.13;
}
double netSalary(double totalsalary)
{
    double tax = incometax(totalsalary);
    return totalsalary - tax;
}
int findminindex(const double arr[], int size)
{
    int minindex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minindex]) {
            minindex = i;
        }
    }
    return minindex;
}
void findmaxelement(const double arr[], int size, double& maxvalue, int& maxindex)
{
    maxvalue = arr[0];
    maxindex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxvalue) {
            maxvalue = arr[i];
            maxindex = i;
        }
    }
}
int elementsgreater(const double arr[], int size, double threshold)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) {
            count++;
        }
    }
    return count;
}
double sumarray(const double arr[], int size)
{
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double bonuspercent = 15.0;
    cout << "Введите количество работников: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Ошибка: количество работников должно быть положительным числом!" << endl;
        return 1;
    }
    int* hours = new int[n];
    double* rate = new double[n];
    double* salary = new double[n];
    double* tax = new double[n];
    double* netsalary = new double[n];
    cout << "\nВведите данные о " << n << " работниках:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nРаботник №" << i + 1 << endl;
        cout << "Количество отработанных часов: ";
        cin >> hours[i];
        cout << "Ставка почасовой оплаты (руб./час): ";
        cin >> rate[i];
    }
    for (int i = 0; i < n; i++) {
        salary[i] = totalSalary(hours[i], rate[i], bonuspercent);
        tax[i] = incometax(salary[i]);
        netsalary[i] = netSalary(salary[i]);
    }
    int minsalaryindex = findminindex(salary, n);
    double minSalary = salary[minsalaryindex];
    double maxsalary;
    int maxsalaryindex;
    findmaxelement(salary, n, maxsalary, maxsalaryindex);
    int counthighsalary = elementsgreater(netsalary, n, 50000);
    double totaltax = sumarray(tax, n);
    int* highsalaryworkers = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (netsalary[i] > 50000) {
            highsalaryworkers[count] = i;
            count++;
        }
    }
    cout << "\n№  | Часы | Ставка | Зарплата | Налог  | На руки" << endl;
    cout << "---+------+--------+----------+--------+---------" << endl;
    for (int i = 0; i < n; i++) {
        printf("%-2d | %-4d | %-6.0f | %-8.0f | %-6.0f | %-8.0f\n",
            i + 1, hours[i], rate[i], salary[i], tax[i], netsalary[i]);
    }
    cout << "\n1. Меньше всех получил работник №" << minsalaryindex + 1
        << " (" << minSalary << " руб.)" << endl;
    cout << "2. Максимальная зарплата: " << maxsalary << " руб. "
        << "(работник №" << maxsalaryindex + 1 << ")" << endl;
    cout << "3. Работников с зарплатой на руки более 50000 руб.: "
        << counthighsalary << endl;
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