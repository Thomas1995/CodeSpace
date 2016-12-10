#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

ifstream fin("arbint.in");
ofstream fout("arbint.out");

int m, n;
vector<int> arb;
vector<int> arr;

int getSize() {
    int size = 1;
    while (size < n) {
        size <<= 1;
    }
    return size << 1;
}

void buildTree(int left, int right, int ind) {
    if (left == right) {
        arb[ind] = arr[left];
        return ;
    }

    int mid = left + (right - left) / 2;
    buildTree(left, mid, 2 * ind);
    buildTree(mid + 1, right, 2 * ind + 1);
    arb[ind] = max(arb[2 * ind], arb[2 * ind + 1]);
}

int getVal(int left, int right, int lo, int hi, int ind) {
    if (left >= lo && right <= hi)
        return arb[ind];

    int mid = left + (right - left) / 2;
    if (lo > mid) {
        return getVal(mid + 1, right, lo, hi, 2 * ind + 1);
    }

    if (hi <= mid) {
        return getVal(left, mid, lo, hi, 2 * ind);
    }

    return max(getVal(left, mid, lo, hi, 2 * ind),
               getVal(mid + 1, right, lo, hi, 2 * ind  + 1));
}

void update(int ind, int index, int val, int lo, int hi) {
    if (lo == hi) {
        arb[ind] = val;
        return ;
    }

    int mid = lo + (hi - lo) / 2;
    if (index <= mid) {
        update(2 * ind, index, val, lo, mid);
    } else {
        update(2 * ind + 1, index, val, mid + 1, hi);
    }

    arb[ind] = max(arb[2 * ind], arb[2 * ind + 1]);
}

int main() {
    fin >> n >> m;
    arr.resize(n);
    arb.resize(getSize());
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    buildTree(0, n - 1, 1);
    for (int i = 0; i < m; i++) {
        int type, a, b;
        fin >> type >> a >> b;
        if (type) {
            update(1, a- 1, b, 0, n - 1);
        } else {
            cout << getVal(0, n - 1, a - 1, b - 1, 1) << '\n';
        }
    }
}
