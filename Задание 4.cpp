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
    cout << "������� ���������� ������������ �����: ";
    cin >> hours;
    cout << "������� ������ ��������� ������ (���./���): ";
    cin >> rate;
    cout << "������� ������� ������: ";
    cin >> bonuspercent;
    allsalary(hours, rate, bonuspercent, totalsalary, tax, netsalary);
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    cout << "\n�������� ��������: " << basesalary << " ���." << endl;
    cout << "������: " << bonus << " ���." << endl;
    cout << "����� ����������� �����: " << totalsalary << " ���." << endl;
    cout << "���������� ����� (13%): " << tax << " ���." << endl;
    cout << "����� � ������: " << netsalary << " ���." << endl;
    return 0;
}