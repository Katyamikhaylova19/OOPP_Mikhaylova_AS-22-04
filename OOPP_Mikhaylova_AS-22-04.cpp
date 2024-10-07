#include "Boost.h"
#include <conio.h>
#include <windows.h>
#include "Group_Mikhaylova.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Group_Mikhaylova group = Group_Mikhaylova(1, vector<shared_ptr<Student_Mikhaylova>> {});

    while (true)
    {
        cout << "МЕНЮ\n";
        int input;
        cout << "0 - Вывести список группы\n"
            << "1 - Загрузить список группы из файла\n"
            << "2 - Сохранить группу в файл\n"
            << "3 - Добавить студента в группу\n"
            << "4 - Добавить старосту в группу\n"
            << "5 - Очистить группу\n";
        cout << "Выберете команду:\n";

        if ((cin >> input).fail())
            break;

        switch (input)
        {
        case 0:
            cout << group;
            break;
        case 1:
        {
            group.LoadFromFile();
            break;
        }
        case 2:
        {
            group.SaveToFile();
            break;
        }
        case 3:
        {
            group.AddStudent();
        }
        break;
        case 4:
            group.AddElder();
            break;
        case 5:
            group.Clear();
            break;
        default:
            return 0;
            break;
        }
    }
}
