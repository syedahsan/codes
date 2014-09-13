#include<iostream>
using namespace std;

typedef struct nn
{
	nn *next;
	int data;
}node;

node *insert(node *start, int n)
{
	node *p = new node;
	p->next = NULL;
	p->data = n;
	if(start == NULL)
		start = p;
	else
	{
		node *temp = start;
		while(temp->next != NULL) temp = temp->next;
		 temp->next = p;
	}
	return start;

}

void print(node *start)
{
	while(start)
	{
		cout << start->data << " ";
		start = start->next;
	}
}

node* EvenToOdd(node *start)
{
	node *odd = NULL, *even= NULL, *evennext= NULL, *oddnext= NULL;
	while(start)
	{
		if(start->data % 2 != 0)
		{
			if(odd == NULL)
			{
				odd = start;
				oddnext = start;
			}
			else
			{
				oddnext->next = start;
				oddnext = start;
			}
		}
		else
		{
			if(even == NULL)
			{
				even = start;
				evennext = start;
			}
			else
			{
				evennext->next = start;
				evennext = start;
			}
		}
		start = start->next;
	}
	if(odd != NULL)oddnext->next = even;
	if(even != NULL)evennext->next = NULL;
	if(odd == NULL) return even;
	return odd;
}



int main(void)
{
	node *start = NULL;
	int n;
	cin >> n;
	while(n != -1)
	{
		start = insert(start,n);
		cin >> n;
	}
	start = EvenToOdd(start);
	print(start);
	cout << endl;
}
