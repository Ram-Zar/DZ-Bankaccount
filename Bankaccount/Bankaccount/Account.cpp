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