#include <Class/Class.h>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using namespace ClassStu;

void printMenu()
{
    cout << endl << "1. Ввод список элементов" << endl;
    cout << "2. Вставить элемент в список по указанному индексу" << endl;
    cout << "3. Удалить элемент из списка по указанному индексу" << endl;
    cout << "4. Вывести список на экран" << endl;
    cout << "5. Выполнить поиск в списке объекта по определённому критерию" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие:";
}

inline std::ostream& operator<<(std::ostream& os, const ClassType& type)
{
    switch (type)
    {
    case ClassType::Lekture:
        os << "Lecture";
        break;
    case ClassType::Practice:
        os << "Practice";
        break;
    case ClassType::Lab:
        os << "Lab";
        break;
    default:
        os.setstate(std::ios_base::failbit);
        break;
    }
    return os;
}


int main()
{
    InfoGroupCounts groupInfo(4, 5);
    ClassList list;

    int choice = -1;

    while (choice != 0)
    {
        printMenu();
        cin >> choice;
        string searchName;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            int n = 0;
            cout << "Введите каличество элементов: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                string name;
                int hours;
                int temp;
                cout << endl;
                cout << "Введите название элемент " << i + 1 << " : ";
                getchar();
                getline(cin, name);
                cout << "Введите часы элемент " << i + 1 << " : ";
                cin >> hours;
                ClassType type;
                cout << "Введите тип элемент " << i + 1 << " (0 - Lekture, 1 - Practice, 2 - Lab) : ";
                cin >> temp;
                if (temp == 0)
                    type = ClassType::Lekture;
                else if (temp == 1)
                    type = ClassType::Practice;
                else
                    type = ClassType::Lab;
                ClassesPtr newClass = new Classes(name, hours, type);
                list.add(newClass);
                cout << endl;
            }
            break;
        }
        case 2:
        {
            string name;
            int hours;
            int temp;
            system("cls");
            cout << "Введите название: ";
            getchar();
            getline(cin, name);
            cout << "Введите часы: ";
            cin >> hours;
            ClassType type;
            cout << "Введите тип (0-Lekture, 1-Practice, 2-Lab): ";
            cin >> temp;
            if (temp == 0)
                type = ClassType::Lekture;
            else if (temp == 1)
                type = ClassType::Practice;
            else
                type = ClassType::Lab;
            ClassesPtr newClass = new Classes(name, hours, type);

            int index;
            cout << "Введите индекс: ";
            cin >> index;
            list.add(newClass, index);
            break;
        }
        case 3:
        {
            system("cls");
            int index;
            cout << "Введите индекс: ";
            cin >> index;
            list.remove(index);
            break;
        }
        case 4:
        {
            system("cls");
            cout << "       СПИСОК      " << endl;
            for (int i = 0; i < list.size(); ++i)
            {
                ClassesPtr currentClass = list[i];
                cout << left << setw(10) << currentClass->get_name();
                cout << left << setw(5) << currentClass->get_hours();
                cout << left << setw(15) << currentClass->get_type() << endl;;
            }

            break;
        }
        case 5:
        {
            system("cls");
            cout << "Введите название класса для поиска: ";
            getchar();
            getline(cin, searchName);
            for (int i = 0; i < list.size(); ++i)
            {
                if (searchName == list[i]->get_name())
                {
                    cout << "Total hours for " << searchName << " class: " << list.calc_total(searchName, groupInfo) << endl;
                    break;
                }
            }
            cout << "Не найдено!";
            break;
        }
        case 0:
            break;
        default:
            system("cls");
            cout << "Неверный выбор. Попробуйте еще раз" << endl;
            break;
        }
    }
    return 0;
}