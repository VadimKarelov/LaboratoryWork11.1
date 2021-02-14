#include <iostream>
using namespace std;

struct List
{
    int data;
    List* next;
};

List* CreateList(int size)
{
    cout << "Заполнение списка на " << size << " элементов" << endl;
    if (size <= 0)
    {
        cout << "Список не может быть создан" << endl;
        return 0;
    }
    List* first, * p;
    first = NULL;
    cout << "Введите элемент 1: ";
    p = new List;
    cin >> p->data;
    first = p;
    for (int i = 1; i < size; i++)
    {
        List* h = new List;
        p->next = h;
        p = p->next;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> p->data;
        p->next = NULL;
    }
    return first;
}

void PrintList(List* first)
{
    cout << "Вывод списка" << endl;
    if (first == NULL)
        cout << "Список пустой" << endl;
    else
    {
        List* p = first;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void DeleteElements(List* &first)
{
    List* newFirst = first;
    while (first != NULL && first->data % 2 == 0)
    {
        newFirst = first->next;
        delete first;
        first = newFirst;
    }
    while (first != NULL && first->next != NULL)
    {
        if (first->next->data % 2 == 0)
        {
            List* newNextElement = first->next->next;
            delete first->next;
            first->next = newNextElement;
        }
        else
        {
            first = first->next;
        }
    }
    first = newFirst;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    do
    {
        cout << "Введите количество элементов списка" << endl;
        cin >> size;
    } while (size < 1);
    List *list = CreateList(size);
    PrintList(list);
    DeleteElements(list);
    cout << "Список после удаления четных элементов" << endl;
    PrintList(list);
}