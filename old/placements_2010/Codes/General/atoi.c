#include <stdio.h>

int myatoi(char *str) {

	int output=0;
	while(*str == ' ') str++;
	while(*str) {
		if(!(*str<='9' && *str>='0'))
			break;
		output = (output * 10)  + (*str++ - '0');
	}
	return output;
}

int main() {
	
	char inp[20];
	scanf("%[^\n]",inp);

	int ans = myatoi(inp);
	printf("%d\n",ans);

	return 0;
}
