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

Info LRemove(Elem *&first, Elem *&last)
{
	Elem* tmp = first->link->link;
	Info value = last->info;
	delete first->link;
	first->link = tmp;
	return value;
}

int main()
{
	Elem *first = NULL, *last = NULL;
	for (int i = 20; i >= 0; i -= 2)
		LAdd(first, last, i);
	//do
	//{
	//	cout << LRemove(first, last) << " ";
	//} while (first->link->info != 6);
	while (first->link != NULL)
	{
		if (first->link->info != 6)
		{
			Elem* tmp = first->link->link; // 1
			delete first->link; // 2
			first->link = tmp; // 3
		}
		else
			first = first->link;
	}
	cout << endl;
	return 0;
}