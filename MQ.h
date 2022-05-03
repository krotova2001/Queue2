// класс очереди на основе двухсвязного списка
#pragma once
#include "Litem.h"
#include <iostream>
using namespace std;
template<typename T>
class MQ
{
	int h; //размер очереди
	Litem<T>* end; // указатель на конец
	Litem<T>* start; // указатель на начало
public:
	MQ() // конструктор по умолчанию, создаем пустую очередь
	{
		h = 0;
		end = start = nullptr;
	}

	MQ(const MQ& C) // конструктор копирования
	{
		if (end) // если очередь не пуста
		{
			Litem<T>* tmp = start;
			do
			{
				C.Add(tmp);
				tmp = tmp->p;
			} 
			while (tmp);
		}
		else // если очередь пуста
		{
			C.end = C.start = nullptr;
		}
	}
	
	MQ& Add(const T& d) // добавление элемента в очередь
	{
		Litem<T>* N = new Litem<T>; // создаем новый элемент на основе данных
		N->data = d;
		N->p = nullptr; // добавляем всегда в конец очереди, поэтому, указатель на предыдущий элемент всегда пустой
		(start) ? N->n = end, end->p = N : start = N; // если очередь не пуста, то ставим элемент в конец. Если пуста, то едиственный элемент будет и началом и концом
		end = N; // вновь добавленный элемент стоит в конце
		h++;
		return *this;
	}

	MQ&  Pop() // удалить крайний элемент
	{
		if (start) //если очередь не пустая
		{
			Litem<T>* tmp=start;
			(start->p) ? start->p->n = nullptr, start = start->p : end = start = nullptr; // если в очереди больше 1 элемента, то выкидываем первый и предыдщий становится началом.
			// иначе - очередь просто становится пустая
			h--;
			delete tmp;
		}
		return *this;
	}

	MQ& Clear() // полная очистка очереди
	{
		while (!Empty())
		{
			Pop();
		}
	}
	
	int count() { return h; } // показать высоту
	bool Empty() { return !end; } // проверить на пустоту
	
	void Show() //показать очередь
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

