/*
 MISTAKES:
 1. Did not check if the strings are not of equal length
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool stringsArePermuted(string str1, string str2) {
	if(str1.size() != str2.size())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 == str2;
}

int main() {
	cout<<stringsArePermuted("thomamas", "masthoma");

	return 0;
}
