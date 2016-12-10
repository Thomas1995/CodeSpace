#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

vector<string> v;

int main() {

	ifstream f("liste.dat");

	char ch[500];

	while(f.get(ch, 200)) {
		f.get();

		string s;
		for(int i=0;i<strlen(ch);++i) {
			if((ch[i] >= 'A' && ch[i] <= 'Z') || ch[i] == ' ' || ch[i] == '-')
				s.push_back(ch[i]);
		}
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i <= 10; ++i)
		cout << endl;

	int cnt = 0;
	for(auto it : v) {
		cout << it << endl;

		if(++cnt % 30 == 0)
			cout << endl;
	}

	return 0;
}
