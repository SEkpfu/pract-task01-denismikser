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
    cout << "������ ������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours1;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate1;
    cout << "������� ������: ";
    cin >> bonuspercent1;
    cout << "\n������ ������� ���������" << endl;
    cout << "���������� ������������ �����: ";
    cin >> hours2;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate2;
    cout << "������� ������: ";
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
    cout << "\n�������� ������� ���������: " << salary1 << " ���." << endl;
    cout << "�������� ������� ���������: " << salary2 << " ���." << endl;
    cout << "����� �����: " << totalsalary << " ���." << endl;
    if (higherearner == 0) {
        cout << "��� ��������� ���������� ���������� �����" << endl;
    }
    else
    {
        cout << "������ ��������� �������� �" << higherearner << endl;
    }
    return 0;
}