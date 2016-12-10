#include <iostream>
using namespace std;

template <typename T>
class SmartPointer {
	int* refNo;
	T* ptr;

public:
	SmartPointer(T* objPtr) : ptr(objPtr) {
		refNo = new int(1);
	}

	SmartPointer(const SmartPointer& other) {
		ptr = other.ptr;
		refNo = other.refNo;
		++(*refNo);
	}

	SmartPointer(SmartPointer&& other) {
		ptr = other.ptr;
		refNo = other.refNo;
		++(*refNo);
		other.~SmartPointer();
	}

	SmartPointer& operator = (const SmartPointer& other) {
		if(&other != this) {

			if(--(*refNo) == 0) {
				cout<<"Am murit "<<(*(*this));
				delete ptr;
			}

			ptr = other.ptr;
			refNo = other.refNo;
			++(*refNo);
		}

		return *this;
	}

	~SmartPointer() {
		if(--(*refNo) == 0) {
			cout<<"Am murit "<<(*(*this));
			delete ptr;
		}
	}

	T operator * () {
		return *ptr;
	}
};

int main() {
	SmartPointer<int> p(new int(5));
	SmartPointer<int> p2(p);
	SmartPointer<int> p3(new int(7));
	p3 = p2;

	return 0;
}
