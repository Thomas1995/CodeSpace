/*
 MISTAKES:
 none
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename obj, int maxStackSize = 10>
class SetOfStacks {
public:
	void push(obj x) {
		if(stackArray.empty() || stackArray.back().size() == maxStackSize) {
			stack<obj> st;
			st.push(x);
			stackArray.push_back(st);
		}
		else {
			stackArray.back().push(x);
		}
	}

	obj pop() {
		assert(!stackArray.empty());

		obj ret = stackArray.back().top();
		stackArray.back().pop();
		if(stackArray.back().empty())
			stackArray.pop_back();

		return ret;
	}

private:
	vector<stack<obj>> stackArray;
};

int main() {

	return 0;
}
