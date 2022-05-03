#include <iostream>
#include "MQ.h"
using namespace std;

int main()
{
	//демонстрация работы очереди (Задание 1)
	MQ<int> Q1;
	for (int i = 0; i < 10; i++)
	{
		Q1.Add(i);
	}
	Q1.Show();
	Q1.Pop();
	Q1.Show();
//------------------------------------
	//демонстрация клонимрования очереди
	MQ<int> Q2(Q1);
	Q2.Show();


}

