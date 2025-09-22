#include <iostream>
using namespace std;
void inputemployeedata(int& hours, double& rate, double& bonuspercent)
{
    cout << "������� ������ � ���������:" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate;
    cout << "������� ������: ";
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
    cout << "\n�������� ��������: " << basesalary << " ���." << endl;
    cout << "������: " << bonus << " ���." << endl;
    cout << "����� ����������� �����: " << salary << " ���." << endl;
    cout << "���������� ����� (13%): " << tax << " ���." << endl;
    cout << "����� � ������: " << finalsalary << " ���." << endl;
    return 0;
}