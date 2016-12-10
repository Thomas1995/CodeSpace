/*
 MISTAKES:
 1. Forgot to change letter to str[i]
*/

#include <iostream>
#include <string>
using namespace std;

string compressString(string str) {
	if(str.size() == 0)
		return str;

	string compressedString;

	int count = 1;
	char letter = str[0];
	for(int i=1;i<str.size();++i) {
		if(str[i] == str[i-1]) {
			++count;
		}
		else {
			compressedString += letter;
			compressedString += to_string(count);
			count = 1;
			letter = str[i];
		}
	}

	compressedString += letter;
	compressedString += to_string(count);

	if(str.size() <= compressedString.size())
		return str;

	return compressedString;
}

int main() {
	cout<<compressString("abcdewgr")<<"\n";
	cout<<compressString("agghhha")<<"\n";
	cout<<compressString("aaaggqhhh")<<"\n";
	cout<<compressString("ttttttttttttttt")<<"\n";

	return 0;
}
