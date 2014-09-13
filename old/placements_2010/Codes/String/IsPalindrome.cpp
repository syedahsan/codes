/******************************************
  *** IsPalindrome.cpp			***
  *** Checks for palindrome in a	***
  *** string, only considering		***
  *** the alphabets, also not 		***
  *** checking their case 		***
******************************************/

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome( string str ) {

	string changed;
	for( int i=0; i<str.size(); i++) {
		if(str[i] >= 'A' && str[i] <= 'Z')
			changed.push_back(str[i]-'A'+'a');
		else if(str[i] >= 'a' && str[i] <='z')
			changed.push_back(str[i]);
	}

	cout << "Changed String : " << changed << endl;

	for( int i=0, j=changed.size()-1; i <= j ;  ) {
		if( changed[i++] != changed[j--] )
			return false;
	}
	
	return true;
}

int main( int argc, char **argv ) {

	string inp;
	getline(cin,inp);

	( IsPalindrome( inp ) ) ? cout << "A Palindrome" << endl : cout << "Not a Palindrome" << endl;

	return 0;
}
