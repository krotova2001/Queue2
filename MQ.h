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

	void Clone (MQ& const C) 
	{
		if (C.start) // ���� ������� �� �����
		{
			Litem<T>* tmp = C.start;
			while (tmp)
			{
				/*
				Litem<T>* N = new Litem<T>;
				N->data = tmp->data;
				N->p = nullptr;
				(C.start) ? N->n = C.end, C.end->p = N : C.start = N;
				end = N;
				h++;
				tmp = tmp->p;
				*/
				Add(tmp->data);
				tmp = tmp->p;
			}
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

