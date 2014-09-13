#include<iostream>
using namespace std;

class sp1 
{ 
	public: 
		int data; 
		sp1* operator ->() { return this;}; 
}; 

int main() 
{ 
	sp1 t; 
	cin >> t.data; 
	cout << t->data; 
} 

