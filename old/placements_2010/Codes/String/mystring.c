#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *mystrstr(char *haystack, char *needle) {

	char *ind = needle;
	char *ret = haystack;
	int FLAG=0;
	while((*haystack)!='\0') {
		if( (*haystack == *needle) && !FLAG ) {
			ret = haystack++;
			needle++;
			FLAG=1;
		}
		else if( (*haystack == *needle) && FLAG ) {
			haystack++;
			needle++;
		}
		else if( (*needle == '\0') && FLAG ) {
			return ret;
		}
		else if( (*haystack != *needle) && FLAG ) {
			needle = ind;
			FLAG=0;
		}
		else
			haystack++;
	}
	return NULL;
}
void remove_extra_spaces( char *str, char *ret ) {

	int FLAG=0, corner=1;
	
	while( (*str != '\0') ) {
		if( *str != ' ' ) {
			*ret = *str;
			ret++;
			FLAG=0;
			corner=0;
		}
		else if( (*str == ' ') && !FLAG && !corner) {
			*ret = *str;
			ret++;
			FLAG=1;
		}
		str++;
	}
	return;
}
int main() {
	
	char str1[100], str2[20];
	scanf("%[^\n]", str1);
//	scanf(" %s", str2);
	
//	char *new = mystrstr( str1, str2 );
//	printf("%s\n", new);

	char *ret = (char*)malloc(sizeof(char)*strlen(str1));
	remove_extra_spaces( str1, ret );
	printf("%s\n", ret);
	
	return 0;
}
