#include <iostream>
using namespace std;

double incometax(double salary) 
{
    return salary * 0.13;
}
double netsalary(double salary) 
{
    double tax = incometax(salary);
    return salary - tax;
}
double totalsalary(int hours, double rate, double bonuspercent) 
{
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    return basesalary + bonus;
}
int main() 
{   
    setlocale(LC_ALL, "Russian");
    int hours;
    double rate, bonuspercent;
    cout << "������� ���������� ������������ �����: ";
    cin >> hours;
    cout << "������� ������ ��������� ������ (���./���): ";
    cin >> rate;
    cout << "������� ������� ������: ";
    cin >> bonuspercent;
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