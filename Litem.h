//����� �������� ������������ ������ � �������

#pragma once
template<typename T> // ������ ��� ���� ������
struct Litem
{
	T data; // ������
	Litem* p = nullptr; // ��������� �� ���������� ��������
	Litem* n = nullptr; // ��������� �� ��������� �������
};

