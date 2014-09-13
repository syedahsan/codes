/******************************************
  ** Largest Palindrome:		***
  ** Reverse the string and check 	***
  ** for Largest common substring 	***
  ** between the two strings		***
  *****************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* PSUEDO CODE IMPLEMENTATION GIVEN IN WIKIPEDIA */
vector<string> LCS(string str1, string str2) {

	vector<string> common;
	string str;
	int size=0;

	// DYNAMIC ARRAY ALLOCATION
	int **arr = new int* [str1.size()+1];
	for(int i=0; i<str1.size()+1; i++)
		arr[i] = new int [str2.size()+1];
	for(int i=0; i<str1.size()+1; i++)
		for(int j=0; j<str2.size()+1; j++)
			arr[i][j] = 0;

	for(int i=0; i<str1.size(); i++) {
		for(int j=0; j<str2.size(); j++) {
			if(str1[i]==str2[j]) {
				if(i==0 || j==0)
					arr[i+1][j+1] = 1;
				else
					arr[i+1][j+1] = arr[i][j] + 1;
				if(arr[i+1][j+1] > size) {
					size = arr[i+1][j+1];
					//cout << "Size: " << size << endl;
					common.clear();
				}
				if(arr[i+1][j+1] == size) {
					str = str1.substr(i-size+1,size);
					//cout << "Substring: " << str << endl;
					common.push_back(str);
				}
			}
		}
	}
	return common;
}
int main() {

	string input, output;
	cin >> input;

	/* USE THIS IF YOU WANT TO SCAN A WHOLE LINE */
	/* getline(cin, input);	*/

	/* REVERSING THE STRING */
	string::reverse_iterator rev;
	for( rev=input.rbegin(); rev<input.rend(); rev++ )
		output.push_back(*rev);
	
	//cout << "Reverse String: " << output << endl;

	vector<string> lpalin = LCS(input, output);
	for( int i=0; i<lpalin.size(); i++ )
		cout << lpalin[i] << endl;

	return 0;

}
