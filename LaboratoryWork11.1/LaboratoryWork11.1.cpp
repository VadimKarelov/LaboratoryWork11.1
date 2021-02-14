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

void DeleteElements(List *first)
{
    List* p = first;
    while (p->data % 2 == 0)
    {
        List* q = first;
        first = p->next;
        delete q;
        p = first;
    }
    while (p->next != NULL)
    {
        if (p->next->data % 2 == 0)
        {
            List* q = p->next;
            p->next = p->next->next;
            delete q;
        }
    }
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