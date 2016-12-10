/*
 MISTAKES:
 1. did not optimize the > 256 in stringHasUniqueCharsASCII
 2. forgot to return true at the end of stringHasUniqueCharsAZ
*/

#include <iostream>
#include <string>
using namespace std;

// ASCII characters
bool stringHasUniqueCharsASCII(string s) {
	if(s.size() > 256)
		return false;

	bool isInString[257];

	for(int i=0;i<=256;++i)
		isInString[i] = false;

	for(auto c : s)
		if(isInString[c])
			return false;
		else
			isInString[c] = true;

	return true;
}

// characters from A to Z
bool stringHasUniqueCharsAZ(string s) {
	int mask = 0;

	for(auto c : s) {
		int bit = (1<<(c-'a'));
		if(mask & bit)
			return false;
		else
			mask |= bit;
	}

	return true;
}

int main() {
	cout<<stringHasUniqueCharsASCII("arsdhnarszxfgdg4984g94r 9g494r")<<"\n";
	cout<<stringHasUniqueCharsAZ("thomascristian")<<"\n";
	cout<<stringHasUniqueCharsAZ("thomas")<<"\n";

	return 0;
}
