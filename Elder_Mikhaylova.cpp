#include "Elder_Mikhaylova.h"

void Elder_Mikhaylova::ConsoleRead(istream& in)
{
	Student_Mikhaylova::ConsoleRead(in);
	cout << "У старосты с собой журнал (0 - да)? ";
	int input;
	in >> input;
	HasJournal = input == 0;
	cout << "Введите коэффициент авторитета в группе: ";
	in >> CoefficientOfRespect;
	cout << "Староста добавлена\n";
}

void Elder_Mikhaylova::ConsoleWrite(ostream& out)
{
	out << "Староста: " << Surname << ' ' << Name << " - возраст: " << Age << '\n'
		<< "    " << (HasJournal ? "с журналом, " : "без журнала, ") << "авторитет в группе: " << CoefficientOfRespect << '\n';
}

Elder_Mikhaylova::Elder_Mikhaylova()
{
}

Elder_Mikhaylova::~Elder_Mikhaylova()
{
}