#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int hours;
    double rate, bonuspercent, totalsalary;
    cout << "������� ���������� ������������ �����: ";
    cin >> hours;
    cout << "������� ������ ��������� ������ (���./���): ";
    cin >> rate;
    cout << "������� ������� ������: ";
    cin >> bonuspercent;
    double basesalary = hours * rate;
    double bonus = basesalary * (bonuspercent / 100);
    totalsalary = basesalary + bonus;
    cout << "\n���������� �������:" << endl;
    cout << "�������� ��������: " << basesalary << " ���." << endl;
    cout << "������: " << bonus << " ���." << endl;
    cout << "����� �����: " << totalsalary << " ���." << endl;
    return 0;
}