#include <bits/stdc++.h>
using namespace std;

int M[] = {0,0,31,28,31,30,31,30,31,31,30,31,30};

vector< pair<long long, long long> > dts;
multiset<long long> S;

long long readInt() {
	string tmp;

	long long total = 0;

	cin>>tmp; // date
	for(int i=0;i<tmp.size();++i)
		tmp[i] -= '0';

	int year = tmp[3] - 3;
	int month = tmp[5] * 10 + tmp[6];
	int day = tmp[8] * 10 + tmp[9];

	total = year * 365;

	total += M[month] + (day-1);

	if(year == 3 && month > 2)
		total += 1; // 29 feb 2016

	total *= 1440;

	cin>>tmp; // hour
	for(int i=0;i<tmp.size();++i)
		tmp[i] -= '0';

	int hour = tmp[0] * 10 + tmp[1];
	int min = tmp[3] * 10 + tmp[4];

	total += hour * 60 + min;

	//cout<<2013+year<<" "<<month<<" "<<day<<" "<<hour<<" "<<min<<"-->"<<total<<"\n";

	return total;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T,B,C;
	cin>>T;

	string tmp;

	for(int i=1;i<=12;++i) {
		M[i] += M[i-1];
	}

	while(T--) {
		cin>>B>>C;

		dts.clear();
		S.clear();

		for(int i=1;i<=B;++i) {
			cin>>tmp; // garbadge

			int a = readInt();
			int b = readInt() + C;

			dts.push_back(make_pair(a,b));
		}

		sort(dts.begin(), dts.end());

		for(int i=0;i<dts.size();++i) {
			if(!S.empty()) {
				if(*S.begin() <= dts[i].first)
					S.erase(S.begin());
			}

			S.insert(dts[i].second);
		}

		cout<<S.size()<<"\n";
	}

	return 0;
}
