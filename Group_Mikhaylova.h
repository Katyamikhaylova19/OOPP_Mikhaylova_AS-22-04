#pragma once
#include "Boost.h"
#include "Student_Mikhaylova.h"
#include "Elder_Mikhaylova.h"

class Group_Mikhaylova
{
	int Number;
	friend class boost::serialization::access;
	vector<shared_ptr<Student_Mikhaylova>> Students;

public:
	friend ostream& operator << (ostream& out, const Group_Mikhaylova& group);
	void LoadFromFile();
	void SaveToFile();
	Group_Mikhaylova(const int& number, const vector<shared_ptr<Student_Mikhaylova>>& students);
	void Clear();
	void AddStudent();
	void AddElder();

	template<class Archive>
	void Serialize(Archive& ar, const unsigned int version)
	{
		ar& Students;
	}
};