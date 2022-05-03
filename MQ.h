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

	MQ(const MQ& C) // ����������� �����������
	{
		if (end) // ���� ������� �� �����
		{
			Litem<T>* tmp = start;
			do
			{
				C.Add(tmp);
				tmp = tmp->p;
			} 
			while (tmp);
		}
		else // ���� ������� �����
		{
			C.end = C.start = nullptr;
		}
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

	MQ& Clear() // ������ ������� �������
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
		Litem<T>* tmp = end;
		cout << "-------\n";
		do
		{
			cout<<tmp->data << "\n";
			tmp = tmp->n;
		} 
		while (tmp);
	}
};

