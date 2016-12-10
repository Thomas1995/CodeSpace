#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	string s;
	getline(cin, s);

	int n;
	cin>>n;

	string ret;
	string tmp;

	bool inv = true;
	for(int i=0;i<s.size();++i) {
		if(inv) {
			tmp.push_back(s[i]);
		}
		else {
			ret.push_back(s[i]);
		}

		if((i+1) % n == 0) {
			inv = !inv;
			reverse(tmp.begin(), tmp.end());
			ret += tmp;
			tmp.clear();
		}
	}

	reverse(tmp.begin(), tmp.end());
	ret += tmp;

	cout<<ret;

	return 0;
}
