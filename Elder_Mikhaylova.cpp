#include "Elder_Mikhaylova.h"

void Elder_Mikhaylova::ConsoleRead(istream& in)
{
	Student_Mikhaylova::ConsoleRead(in);
	cout << "� �������� � ����� ������ (0 - ��)? ";
	int input;
	in >> input;
	HasJournal = input == 0;
	cout << "������� ����������� ���������� � ������: ";
	in >> CoefficientOfRespect;
	cout << "�������� ���������\n";
}

void Elder_Mikhaylova::ConsoleWrite(ostream& out)
{
	out << "��������: " << Surname << ' ' << Name << " - �������: " << Age << '\n'
		<< "    " << (HasJournal ? "� ��������, " : "��� �������, ") << "��������� � ������: " << CoefficientOfRespect << '\n';
}

Elder_Mikhaylova::Elder_Mikhaylova()
{
}

Elder_Mikhaylova::~Elder_Mikhaylova()
{
}