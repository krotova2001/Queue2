//класс элемента двухсвязного списка в очереди

#pragma once
template<typename T> // шаблон для типа данных
struct Litem
{
	T data; // данные
	Litem* p = nullptr; // указатель на предыдущий эелемент
	Litem* n = nullptr; // указаьель на следующий элемент
};

