#include "Boost.h"
#include "Student_Mikhaylova.h"

BOOST_CLASS_IMPLEMENTATION(Student_Mikhaylova, boost::serialization::level_type::object_serializable)

void Student_Mikhaylova::ConsoleRead(istream& in)
{
	cout << "Введите фамилию: ";
	in >> Surname;
	cout << "Введите имя: ";
	in >> Name;
	cout << "Введите возраст: ";
	in >> Age;
}

void Student_Mikhaylova::ConsoleWrite(ostream& out)
{
	out << "Студент: " << Surname << " " << Name << " - возраст: " << Age << '\n';
}

Student_Mikhaylova::Student_Mikhaylova()
{
}

Student_Mikhaylova::~Student_Mikhaylova()
{
}
