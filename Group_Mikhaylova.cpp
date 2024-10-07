#include "Boost.h"
#include "Group_Mikhaylova.h"

BOOST_CLASS_EXPORT(Elder_Mikhaylova)

using boost::archive::archive_flags;

ostream& operator<<(ostream& out, const Group_Mikhaylova& group)
{
    out << " - ������ �" << group.Number << '\n';
    if (group.Students.empty())
    {
        out << "������ �����\n";
    }
    else
    {
        for (const auto& student : group.Students)
            student->ConsoleWrite(out);
    }
    return out;
}

void Group_Mikhaylova::LoadFromFile()
{
    Students.clear();

    string filename;
    cout << "������� ��� ����� ��� ��������: \n";
    cin.ignore();
    getline(cin, filename);

    ifstream fin;
    fin.open(filename, ios::in);

    if (fin.is_open()) {
        boost::archive::text_iarchive load(fin, archive_flags::no_header);
        load >> Students;
        cout << "�������� ������ �������!\n";
    }
    else {
        cout << "�������, ���-�� ����� �� ���.. :(\n";
    }
}

void Group_Mikhaylova::SaveToFile()
{
    string filename;
    cout << "������� ��� ����� ��� ����������: \n";
    cin.ignore();
    getline(cin, filename);

    ofstream fout;
    fout.open(filename, ios::out);

    if (fout.is_open()) {

        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << Students;

        cout << "���������� ������ �������!\n";
    }

    else {
        cout << "�������, ���-�� ����� �� ���.. :(\n";
    }
}

Group_Mikhaylova::Group_Mikhaylova(const int& number, const vector<shared_ptr<Student_Mikhaylova>>& students)
{
    Number = number;
    Students = students;
}

void Group_Mikhaylova::Clear()
{
    cout << "�� ������������� ������ ������� ���� ������ ������? (������� 0 ��� �������������)\n";
    int input;
    if ((cin >> input).fail() || input != 0)
    {
        cout << "������...\n";
        return;
    }
    else
    {
        Students.clear();
        cout << "�������� �������� ������ �������\n";
    }
}

void Group_Mikhaylova::AddStudent()
{
    Student_Mikhaylova* student = new Student_Mikhaylova();
    student->ConsoleRead(cin);
    Students.push_back(shared_ptr<Student_Mikhaylova>(student));
}

void Group_Mikhaylova::AddElder()
{
    Elder_Mikhaylova* elder = new Elder_Mikhaylova();
    elder->ConsoleRead(cin);
    Students.push_back(shared_ptr<Elder_Mikhaylova>(elder));
}