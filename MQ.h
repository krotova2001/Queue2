// ����� ������� �� ������ ������������ ������
#pragma once
#include "Litem.h"
#include <iostream>
using namespace std;
template<typename T>
class MQ
{
	int h; //������ �������
	Litem<T>* end; // ��������� �� �����
	Litem<T>* start; // ��������� �� ������
public:
	MQ() // ����������� �� ���������, ������� ������ �������
	{
		h = 0;
		end = start = nullptr;
	}

	Litem<T>* Clone (MQ& const C) // ������� ������������ �������
	{
		if (C.start) // ���� ������� �� �����
		{
			Litem<T>* tmp = C.start; // ������� ��������� �������
			while (tmp) // ���� ������� �� ������
			{
				Add(tmp->data); // ���������
				tmp = tmp->p; // �������� ������� �� ����������
			}
		}
		return start; // ���������� ������ ������� �����-��
	}

	MQ operator+(MQ& const P) // ���������� ��������� + 
	{
		MQ N; // ��������� ������
		N.Clone(*this); // ��������� � ��� ������� �������
		if (P.start) // ���� ���� ��� ���������, ����������
		{
			Litem<T>* tmp = P.start; // ������� ��������� �������
			while (tmp) // ���� ������� �� ������
			{
				N.Add(tmp->data); // ���������
				tmp = tmp->p; // �������� ������� �� ����������
			}
		}
		return N;
	}

	MQ operator*(MQ& const P) //������� ���������� ���������� ���������
	{ // �� ��������� ������� ������� ���������� ��������
		MQ N; // ��������� ������
		for (Litem<T>* i = start;i; i=i->p) // ������� ������� ������ ���� ����������
		{
			for (Litem<T>* j = P.start;j; j=j->p)
			{
				if (i->data==j->data)
				{
					N.Add(j->data); // � ��������� �� � ����� ������
				}
			}
		}
		return N;
	}
	
	MQ& Add(const T& d) // ���������� �������� � �������
	{
		Litem<T>* N = new Litem<T>; // ������� ����� ������� �� ������ ������
		N->data = d;
		N->p = nullptr; // ��������� ������ � ����� �������, �������, ��������� �� ���������� ������� ������ ������
		(start) ? N->n = end, end->p = N : start = N; // ���� ������� �� �����, �� ������ ������� � �����. ���� �����, �� ����������� ������� ����� � ������� � ������
		end = N; // ����� ����������� ������� ����� � �����
		h++;
		return *this;
	}

	MQ&  Pop() // ������� ������� �������
	{
		if (start) //���� ������� �� ������
		{
			Litem<T>* tmp=start;
			(start->p) ? start->p->n = nullptr, start = start->p : end = start = nullptr; // ���� � ������� ������ 1 ��������, �� ���������� ������ � ��������� ���������� �������.
			// ����� - ������� ������ ���������� ������
			h--;
			delete tmp;
		}
		return *this;
	}

	void Clear() // ������ ������� �������
	{
		while (!Empty())
		{
			Pop();
		}
	}
	
	int count() { return h; } // �������� ������
	bool Empty() { return !end; } // ��������� �� �������
	
	void Show() //�������� �������
	{
		if (start)
		{

		
		Litem<T>* tmp = end;
		cout << "-------\n";
		do
		{
			cout<<tmp->data << "\n";
			tmp = tmp->n;
		} 
		while (tmp);
		}
	}
};

