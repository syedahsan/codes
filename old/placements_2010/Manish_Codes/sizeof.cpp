#include<iostream>
using namespace std;

typedef struct ss
{
	int a;
	float b;
	char c;
}
node;

int main(void)
{
	node *p = NULL;
	cout << sizeof(node) << endl;
	int size = (char*)(p+1) - (char*)p;
	cout << size << endl;

}
