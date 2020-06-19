#pragma once
#include "Account.h"
#include <iostream>
using namespace std;
class Bankomat
{
	Account *m_a;
	static Money m_bank;
public:
	Bankomat(Account *a)
	{
		m_a = a;
	}
	void GetCash(int R, int K)
	{
		Money t_bank(R, K);
		if (m_bank < t_bank)
		{
			cout << "\n��������, � ��������� ������������ �������. �������� ��������";
		}
		else
		{
			if (!m_a->GetCash(R, K))
			{
				m_bank = m_bank-t_bank;
				cout << "\n�������";
			}
		}
	}
	void PutCash(int R, int K)
	{
		if (!m_a->PutCash(R, K))
		{
			m_bank = m_bank + Money(R, K);
			cout << "\n�������";
		}
	}
};

