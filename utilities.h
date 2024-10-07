#pragma once
#include <iostream>

using namespace std;

template <typename T>
void TryInput(T& var)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "ќшибка! ¬ведите корректные данные: ";
		cin >> var;
	}
}