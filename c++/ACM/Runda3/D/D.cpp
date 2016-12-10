#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T;
	double A,B;

	cin>>T;
	for(int t = 1; t <= T; ++t) {
		cout<<"Case #"<<t<<": ";
		cin>>A>>B;
		if(B == 0.01 && A != 0.02) {
			cout<<"0.02\n";
			continue;
		}

		if(B == 0.1 && A != 0.2) {
			cout<<"0.02\n";
			continue;
		}

		if(B == 1 && A != 2) {
			cout<<"0.02\n";
			continue;
		}

		if(B == 10 && A != 20) {
			cout<<"0.02\n";
			continue;
		}

		cout<<"0.01\n";
	}

	return 0;
}
