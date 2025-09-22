#include <iostream>
using namespace std;
double monthlysalary(int hours, double rate, double bonuspercent)
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
double incometax(double totalsalary)
{
    return totalsalary * 0.13;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int workers = 4;
    const int months = 3;
    const double bonuspercent = 15.0;
    double rates[workers] = { 500, 450, 600, 400 };
    int hours[workers][months];
    double data[workers][months][3];
    cout << "Введите количество отработанных часов:" << endl;
    for (int worker = 0; worker < workers; worker++)
    {
        cout << "\nРаботник №" << worker + 1 << " (ставка: " << rates[worker] << " руб./час)" << endl;
        for (int month = 0; month < months; month++)
        {
            cout << "Месяц " << month + 1 << ": ";
            cin >> hours[worker][month];
        }
    }
    for (int worker = 0; worker < workers; worker++)
    {
        for (int month = 0; month < months; month++)
        {
            double salary = monthlysalary(hours[worker][month], rates[worker], bonuspercent);
            double tax = incometax(salary);
            double netsalary = salary - tax;
            data[worker][month][0] = salary;
            data[worker][month][1] = tax;
            data[worker][month][2] = netsalary;
        }
    }
    cout << "\nРаб\\Мес |";
    for (int month = 0; month < months; month++) {
        cout << " Мес " << month + 1 << " (зп/нал/руки) |";
    }
    cout << endl;
    for (int worker = 0; worker < workers; worker++)
    {
        cout << "Раб №" << worker + 1 << "  |";
        for (int month = 0; month < months; month++)
        {
            printf(" %6.0f/%-4.0f/%-5.0f |",
                data[worker][month][0],
                data[worker][month][1],
                data[worker][month][2]);
        }
        cout << endl;
    }
    double firstworkersecondmonth = data[0][1][2];
    cout << "\n1. Первый работник получил на руки во втором месяце: " << firstworkersecondmonth << " руб." << endl;
    double thirdworkertotaltax = 0;
    for (int month = 0; month < months; month++)
    {
        thirdworkertotaltax += data[2][month][1];
    }
    cout << "2. Общий налог третьего работника за год: " << thirdworkertotaltax << " руб." << endl;
    double maxsalarythirdmonth = data[0][2][0];
    int bestWorkerThirdMonth = 0;
    for (int worker = 1; worker < workers; worker++)
    {
        if (data[worker][2][0] > maxsalarythirdmonth)
        {
            maxsalarythirdmonth = data[worker][2][0];
            bestWorkerThirdMonth = worker;
        }
    }
    cout << "3. В третьем месяце больше всех заработал работник №" << bestWorkerThirdMonth + 1 << " (" << maxsalarythirdmonth << " руб.)" << endl;
    double totalbrigadesalary = 0;
    for (int worker = 0; worker < workers; worker++)
    {
        for (int month = 0; month < months; month++)
        {
            totalbrigadesalary += data[worker][month][0];
        }
    }
    cout << "4. Общая сумма, заработанная бригадой за год: " << totalbrigadesalary << " руб." << endl;
    return 0;
}