#include <iostream>
#include <queue>
#include "BST.h"

using namespace std;

int main() {

	BinarySearchTree test;
	int temp=0;
	while(true) {
		cin >> temp;
		if(temp==-1)
			break;
		test.insert(temp);
	}

	test.print();
	cout << endl;

//	test.levelorder();
//	cout << "\nDepth = " << test.depth() << endl; 

//	test.allorder();

	test.DFS();
	cout << endl;

	return 0;
}
