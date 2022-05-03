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

	Litem<T>* Clone (MQ& const C) // функция клонирования очереди
	{
		if (C.start) // если очередь не пуста
		{
			Litem<T>* tmp = C.start; // создаем временный элемент
			while (tmp) // пока элемент не пустой
			{
				Add(tmp->data); // добавляем
				tmp = tmp->p; // сдвигаем элемент на предыдущий
			}
		}
		return start; // возвращаем начало очереди зачем-то
	}

	MQ operator+(MQ& const P) // перегрузка оператора + 
	{
		MQ N; // временный объект
		N.Clone(*this); // клонируем в нее текущую очередь
		if (P.start) // если есть что прибавить, прибавляем
		{
			Litem<T>* tmp = P.start; // создаем временный элемент
			while (tmp) // пока элемент не пустой
			{
				N.Add(tmp->data); // добавляем
				tmp = tmp->p; // сдвигаем элемент на предыдущий
			}
		}
		return N;
	}

	MQ operator*(MQ& const P) //функция добавления одинаковых элементов
	{ // не учитывает двойные встречи одинаковых значений
		MQ N; // временный объект
		for (Litem<T>* i = start;i; i=i->p) // обычным двойным циклом ищем совпадения
		{
			for (Litem<T>* j = P.start;j; j=j->p)
			{
				if (i->data==j->data)
				{
					N.Add(j->data); // и добавляем их в новый объект
				}
			}
		}
		return N;
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

	void Clear() // полная очистка очереди
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

