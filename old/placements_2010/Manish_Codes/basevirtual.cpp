#include<iostream>
using namespace std;

class Exforsys 
{ 
	protected: 
		int x; 
}; 

class Exf1:virtual public Exforsys 
{ }; 

class Exf2:virtual public Exforsys 
{ }; 

class Training:public Exf1,public Exf2 
{ 
	public: 
		int example() 
		{ 
			return x; 
		} 
};
