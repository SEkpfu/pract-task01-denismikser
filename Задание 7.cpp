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
    cout << "������ ��� ������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours1;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate1;
    cout << "\n������ ��� ������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours2;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate2;
    cout << "\n������ ��� �������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours3;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate3;
    cout << "\n������ ��� ���������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours4;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate4;
    cout << "\n������ ��� ������ ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours5;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate5;
    double salary1 = totalsalary(hours1, rate1, bonuspercent);
    double salary2 = totalsalary(hours2, rate2, bonuspercent);
    double salary3 = totalsalary(hours3, rate3, bonuspercent);
    double salary4 = totalsalary(hours4, rate4, bonuspercent);
    double salary5 = totalsalary(hours5, rate5, bonuspercent);
    double totalsum = salary1 + salary2 + salary3 + salary4 + salary5;
    double averagesalary = totalsum / 5;
    cout << "\n�������� ������� ���������: " << salary1 << " ���." << endl;
    cout << "�������� ������� ���������: " << salary2 << " ���." << endl;
    cout << "�������� �������� ���������: " << salary3 << " ���." << endl;
    cout << "�������� ���������� ���������: " << salary4 << " ���." << endl;
    cout << "�������� ������ ���������: " << salary5 << " ���." << endl;
    cout << "\n����� �����, ������������ ��������: " << totalsum << " ���." << endl;
    cout << "������� �������� � �������: " << averagesalary << " ���." << endl;
    return 0;
}