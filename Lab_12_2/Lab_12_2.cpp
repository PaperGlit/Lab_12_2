#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{
	Elem *link;
	Info info;
};

void LAdd(Elem *&first, Elem *&last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void LRemove(Elem *&first, int k)
{
	Elem *first1 = first;
	while (first->link != NULL)
	{
		if (first->info != k)					//Надсилає перший елемент списку на позицію із значенням k
			first = first->link;
		else									//Вилучає елементи списку після елементу із значенням k
		{
			Elem* tmp = first->link->link;
			delete first->link;
			first->link = tmp;
		}
	}
	first = first1;								//Повертає перший елемент на початкову позицію списку
}

void LPrint(Elem *&first)
{
	Elem* first1 = first;
	while (first != NULL)
	{
		cout << first->info << "  ";
		first = first->link;
	}
	first = first1;
	cout << endl;
}

int main()
{
	int k;
	Elem *first = NULL, *last = NULL;
	for (int i = 0; i <= 10; i++)
		LAdd(first, last, i);
	LPrint(first);
	cout << "k = "; cin >> k;
	LRemove(first, k);
	LPrint(first);
	return 0;
}