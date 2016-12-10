#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;

template<typename Ret, typename Param>
std::function<Ret(Param)> memo(std::function<Ret(Param)> fct) {
	return [fct](Param p) {
		static unordered_map<Param, Ret> m;
		if(m.find(p) != m.end()) {
			return m[p];
		}
		m[p] = fct(p);
		return m[p];
	};
}

int fact(int n) {
	if(n == 0)
		return 1;
	return n * fact(n-1);
}

int main() {
	std::function<int(int)> x(fact);
	std::function<int(int)> factmem = memo(x);
	cout<<factmem(5)<<"\n";

	return 0;
}
