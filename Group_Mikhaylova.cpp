#include "Boost.h"
#include "Group_Mikhaylova.h"

BOOST_CLASS_EXPORT(Elder_Mikhaylova)

using boost::archive::archive_flags;

ostream& operator<<(ostream& out, const Group_Mikhaylova& group)
{
    out << " - Группа №" << group.Number << '\n';
    if (group.Students.empty())
    {
        out << "Группа пуста\n";
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
    cout << "Введите имя файла для загрузки: \n";
    cin.ignore();
    getline(cin, filename);

    ifstream fin;
    fin.open(filename, ios::in);

    if (fin.is_open()) {
        boost::archive::text_iarchive load(fin, archive_flags::no_header);
        load >> Students;
        cout << "Загрузка прошла успешно!\n";
    }
    else {
        cout << "Кажется, что-то пошло не так.. :(\n";
    }
}

void Group_Mikhaylova::SaveToFile()
{
    string filename;
    cout << "Введите имя файла для сохранения: \n";
    cin.ignore();
    getline(cin, filename);

    ofstream fout;
    fout.open(filename, ios::out);

    if (fout.is_open()) {

        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << Students;

        cout << "Сохранение прошло успешно!\n";
    }

    else {
        cout << "Кажется, что-то пошло не так.. :(\n";
    }
}

Group_Mikhaylova::Group_Mikhaylova(const int& number, const vector<shared_ptr<Student_Mikhaylova>>& students)
{
    Number = number;
    Students = students;
}

void Group_Mikhaylova::Clear()
{
    cout << "Вы действительно хотите удалить весь список группы? (введите 0 для подтверждения)\n";
    int input;
    if ((cin >> input).fail() || input != 0)
    {
        cout << "Отмена...\n";
        return;
    }
    else
    {
        Students.clear();
        cout << "Операция удаления прошла успешно\n";
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