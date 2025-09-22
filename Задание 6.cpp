#include <iostream>
#include <Windows.h>
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
double netsalary(double totalsalary) {
    double tax = incometax(totalsalary);
    return totalsalary - tax;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int hours1, hours2;
    double rate1, bonuspercent1, rate2, bonuspercent2;
    char surname1[21], surname2[21];
    cout << "������ ������� ���������" << endl;
    cout << "������� (�� ����� 20 ��������): ";
    cin >> surname1;
    cout << "���������� ������������ �����: ";
    cin >> hours1;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate1;
    cout << "������� ������: ";
    cin >> bonuspercent1;
    cout << "\n������ ������� ���������" << endl;
    cout << "������� (�� ����� 20 ��������): ";
    cin >> surname2;
    cout << "���������� ������������ �����: ";
    cin >> hours2;
    cout << "������ ��������� ������ (���./���): ";
    cin >> rate2;
    cout << "������� ������: ";
    cin >> bonuspercent2;
    double salary1 = totalsalary(hours1, rate1, bonuspercent1);
    double salary2 = totalsalary(hours2, rate2, bonuspercent2);
    double tax1 = incometax(salary1);
    double tax2 = incometax(salary2);
    double netsalary1 = netsalary(salary1);
    double netsalary2 = netsalary(salary2);
    cout << "\n�������: " << surname1 << ", �� ����: " << netsalary1 << " ���., �����: " << tax1 << " ���." << endl;
    cout << "�������: " << surname2 << ", �� ����: " << netsalary2 << " ���., �����: " << tax2 << " ���." << endl;
    cout << "\n������� ���������� � ��������� �� ���� ������ 1000 ���.:" << endl;
    bool lowsalary = false;
    if (netsalary1 < 1000) {
        cout << "- " << surname1 << " (" << netsalary1 << " ���.)" << endl;
        lowsalary = true;
    }
    if (netsalary2 < 1000) {
        cout << "- " << surname2 << " (" << netsalary2 << " ���.)" << endl;
        lowsalary = true;
    }
    if (!lowsalary) {
        cout << "����� ���������� ���" << endl;
    }
    cout << "\n������� � ������ � ��������� ������ (����� > 50 ���.):" << endl;
    bool hightax = false;
    if (tax1 > 50) {
        int len = 0;
        while (surname1[len] != '\0' && len < 20) {
            len++;
        }
        if (len > 0) {
            cout << "- " << surname1[0] << "-" << surname1[len - 1] << " (" << surname1 << ")" << endl;
            hightax = true;
        }
    }
    if (tax2 > 50) {
        int len = 0;
        while (surname2[len] != '\0' && len < 20) {
            len++;
        }
        if (len > 0) {
            cout << "- " << surname2[0] << "-" << surname2[len - 1] << " (" << surname2 << ")" << endl;
            hightax = true;
        }
    }
    if (!hightax) {
        cout << "����� ���������� ���" << endl;
    }
    return 0;
}