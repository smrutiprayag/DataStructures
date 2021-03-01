#include <iostream>
using namespace std;
class DoubleLinkedList
{
public:
	DoubleLinkedList *prev;
	int data;
	DoubleLinkedList  *next;
}*first = NULL;

void create(int a[], int n)
{
	//create a pointer to represent the last node
	DoubleLinkedList *last, *t;

	//create fist node
	first = new DoubleLinkedList();
	first->data = a[0];
	first->prev = first->next = NULL;
	last =first;

	for (int i = 1; i < n; i++)
	{
		t = new DoubleLinkedList();
		t->data = a[i];
		t->prev = last;
		t->next = last->next;
		last->next = t;
		last = t;

	}
}


void Display(DoubleLinkedList *p)
{
	while (p)
	{
		cout << "element" << p->data << endl;
		p = p->next;

	}

}
int count(DoubleLinkedList *p)
{
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}


int main()
{

	int a[5] = { 1,2,3,4,5 };
	cout << "creating a Double LinkedList"<<endl;
	create(a, 5);
	Display(first);
	int c = count(first);
	cout << "Number of elements in the Double LinkedList " << c<<endl;
	cout << "exitting";
}
