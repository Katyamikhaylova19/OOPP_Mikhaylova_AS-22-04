#include "Boost.h"
#include "Student_Mikhaylova.h"

BOOST_CLASS_IMPLEMENTATION(Student_Mikhaylova, boost::serialization::level_type::object_serializable)

void Student_Mikhaylova::ConsoleRead(istream& in)
{
	cout << "������� �������: ";
	in >> Surname;
	cout << "������� ���: ";
	in >> Name;
	cout << "������� �������: ";
	in >> Age;
}

void Student_Mikhaylova::ConsoleWrite(ostream& out)
{
	out << "�������: " << Surname << " " << Name << " - �������: " << Age << '\n';
}

Student_Mikhaylova::Student_Mikhaylova()
{
}

Student_Mikhaylova::~Student_Mikhaylova()
{
}
