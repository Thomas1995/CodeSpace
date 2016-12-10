/*
 MISTAKES:
 none
*/

#include <iostream>
using namespace std;

struct ListNode {
	ListNode* next;
	int val;
	ListNode(int value) : val(value), next(NULL) {}
};

ListNode* read() {
	int n, m;
	cin>>m>>n;
	ListNode* head = new ListNode(1);
	ListNode* last = head;

	for(int i=2;i<=m;++i) {
		ListNode* tmp = new ListNode(i);
		last->next = tmp;
		last = tmp;
	}

	ListNode* cycleStart = last;

	for(int i=m+1;i<=n;++i) {
		ListNode* tmp = new ListNode(i);
		last->next = tmp;
		last = tmp;
	}

	last->next = cycleStart;

	return head;
}

ListNode* FindBeginning(ListNode* head) {
	ListNode *fast = head, *slow = head;
	do {
		fast = fast->next->next;
		slow = slow->next;
	}
	while(fast != slow);

	slow = head;

	while(fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
}

int main() {
	cout<<FindBeginning(read())->val<<"\n";

	return 0;
}
