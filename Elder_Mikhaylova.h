#pragma once
#include "Boost.h"
#include "Student_Mikhaylova.h"

class Elder_Mikhaylova :
	public Student_Mikhaylova
{
	friend class boost::serialization::access;

private:
	bool HasJournal = false;
	float CoefficientOfRespect;
	
public:
	BOOST_SERIALIZATION_SPLIT_MEMBER()

	void ConsoleRead(istream& in);
	void ConsoleWrite(ostream& out);
	Elder_Mikhaylova();
	virtual ~Elder_Mikhaylova();
	
	template<class Archive>
	void save(Archive& ar, const unsigned int version) const
	{
		ar& boost::serialization::base_object<Student_Mikhaylova>(*this);
		ar << HasJournal;
		ar << CoefficientOfRespect;
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version)
	{
		ar >> boost::serialization::base_object<Student_Mikhaylova>(*this);
		ar >> HasJournal;
		ar >> CoefficientOfRespect;
	}
};