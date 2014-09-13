#include<iostream>
using namespace std;

class Vehicle   //This denotes the base class of C++ virtual function
{ 
	public: 
		virtual void Make()   //This denotes the C++ virtual function
		{ 
			cout <<"Member function of Base Class Vehicle Accessed"<<endl; 
		} 
};

class FourWheeler : public  Vehicle 
{ 
	public: 
		void Make() 
		{ 
			cout<<"Virtual Member function of Derived class FourWheeler Accessed"<<endl; 
		} 
};

int main() 
{ 
	Vehicle *a, *b; 
	a = new Vehicle(); 
	a->Make(); 
	b = new FourWheeler(); 
	b->Make(); 
}
