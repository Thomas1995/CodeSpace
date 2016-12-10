/*
 MISTAKES:
 none
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char* str) {
	int strLength = strlen(str);
	int halfLength = strLength / 2;
	for(int i=0;i<halfLength;++i)
		swap(str[i], str[strLength-i-1]);
}

int main() {
	char s[] = "Thomas Cristian Suditu";
	reverse(s);
	cout<<s;

	return 0;
}
