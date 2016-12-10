#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

void hello(int& i, char c) {
    i = 8;
}

void inc(int n) {
    int x = 100000/n;
    for(int i=1;i<=x;++i);
}

int main() {
    vector<thread> v;
    //int n = max(1, (int)thread::hardware_concurrency());
    int n;
    cin>>n;

    for(int i=1;i<=n;++i) {
        v.push_back(thread(inc, n));
    }

    for_each(v.begin(), v.end(), mem_fn(&thread::detach));
}
