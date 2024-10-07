#pragma once
#include "Boost.h"

class Student_Mikhaylova
{
	friend class boost::serialization::access;

protected:
	string Name;
	string Surname;
	int Age;

public:
	virtual void ConsoleRead(istream& in);
	virtual void ConsoleWrite(ostream& out);
	Student_Mikhaylova();
	virtual ~Student_Mikhaylova();

	template <class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& Name;
		ar& Surname;
		ar& Age;
	}
};