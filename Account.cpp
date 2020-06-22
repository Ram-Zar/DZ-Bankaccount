#include "Account.h"
#include <clocale>
int Account::s_AcNum = 0;
void Account::AccView()
{
	static int i = -1;
	++i;
	if (i != 0)
	{
		Per_cent_plus();
	}	
	cout << "\n////INFORMATION////\n";
	cout << "������� ��������� �����: " << m_surname << "\n����� �����: " << m_AcNum << "\n�������: " << setprecision(3) << m_per_cent << "%\n������: ";
	m_balance.print();
	cout << " (";
	Print_Num();
	cout << ")";
	cout << "\n���� �����������: ";
	m_date.printDate();		
}
 bool Account::GetCash(int R, int K)
{
	Money temp(R, K);
	if (m_balance < temp)
	{
		cout << "\n��������.� ��� ������������ ������� �� �����";
		return 1;
	}
	else
	{
		m_balance = m_balance - temp;
		cout << "\n��������� �����: " << R << "," << K << "\n������: ";
		m_balance.print();
		return 0;
	}
}
istream& operator>>(istream& in, Account& a)
{
	cout << "������� �������:";
	in >> a.m_surname;
	while (a.m_surname[0] == '\0')
	{
		cout << "������� �������:";
		in >> a.m_surname;
	}
	cout << "\n������� ����������� ������� ����������\n�������=";//����� ���������� ������������ �����. ����
	in >> a.m_per_cent;
	cout << "\n������� ����� � ������. ������: 00,00\n�����=";//� ��� ����
	long R;
	int K;
	scanf_s("%ld%*c%d", &R, &K);
	if (a.m_balance.SetAcc(R, K))
	{
		cout << "\n������������ �����";
		cout << "\n������� ����� � ������. ������: 00,00\n�����=";
		scanf_s("%ld%*c%d", &R, &K);
	}
	while (a.m_balance == 0.0)
	{
		cout << "\n������� ����� � ������. ������: 00,00\n�����=";//� ��� ����
		long R;
		int K;
		scanf_s("%ld%*c%d", &R, &K);
		a.m_balance.SetAcc(R, K);
	}
	cout << "\n������� ����������� ����. ������:����.MM.��: ";
	char date[11];
	cin >> date;
	a.m_date(date);
	++a.s_AcNum;
	a.m_AcNum = a.s_AcNum;
	a.reg_time = time(NULL);
	return in;
}