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


ItemClassPtr read_new_class() {
    string name;
    int hours;
    int temp;
    cout << endl;
    cout << "Введите название  : ";
    getchar();
    getline(cin, name);
    cout << "Введите часы элемент  : ";
    cin >> hours;
    cout << "Введите тип элемент (0 - Lekture, 1 - Practice, 2 - Lab) : ";
    cin >> temp;
    if (temp == 0)
        return make_unique<ClassLecture>(name, hours);
    else if (temp == 1)
        return make_unique<ClassPractice>(name, hours);
    else
        return make_unique<ClassLab>(name, hours);
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
            cout << "Введите количество элементов: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Введите элемент " << i + 1 << " : ";
                list.add(read_new_class());
                cout << endl;
            }
            break;
        }
        case 2:
        {
            ItemClassPtr newClass = read_new_class();
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
            cout << endl << "Элемент успешно удален! " << endl;
            break;
        }
        case 4:
        {
            system("cls");
            cout << "       СПИСОК      " << endl;
            for (int i = 0; i < list.size(); ++i)
            {
                list[i]->print(cout, groupInfo);
            }
            break;
        }
        case 5:
        {
            system("cls");
            int temp = 0;
            cout << "Введите название класса для поиска: ";
            getchar();
            getline(cin, searchName);
            int total_hours = list.calc_total(searchName, groupInfo);
            if (total_hours == 0)
                cout << "Не найдено!";
            else
                cout << "Total hours for " << searchName << " class: " << total_hours << endl;
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