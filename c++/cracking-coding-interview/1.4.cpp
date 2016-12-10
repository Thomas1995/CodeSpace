/*
 MISTAKES:
 1. Forgot --j in second for
*/

#include <iostream>
#include <cstring>
using namespace std;

void replaceSpaces(char* str, int len) {
	int countSpaces = 0;
	for(int i=0;i<len;++i)
		if(str[i] == ' ')
			++countSpaces;

	for(int i=len+countSpaces*2-1, j=len-1;i>=0;--i, --j) {
		if(str[j] == ' ') {
			str[i] = '0';
			str[--i] = '2';
			str[--i] = '%';
		}
		else str[i] = str[j];
	}
}

int main() {
	char c[] = "Thomas Cristian Suditu000000000000000000";
	char c2[] = "       abc                 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	replaceSpaces(c, 22);
	replaceSpaces(c2, 27);

	cout<<c<<"\n"<<c2<<"\n";

	return 0;
}
