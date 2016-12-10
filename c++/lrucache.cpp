#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{

    int size;
    unordered_map<int, list< pair<int,int> >::iterator> m;
    list< pair<int,int> > li;

public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if(m.find(key) != m.end()) {
            auto it = m[key];
            int ret = (*it).second;

            li.erase(it);
            li.push_back(make_pair(key, ret));
            it = li.end();
            m[key] = --it;

            return ret;
        }

        return -1;
    }

    void set(int key, int value) {
        if(m.find(key) != m.end()) {
            auto it = m[key];
            li.erase(it);
            li.push_back(make_pair(key, value));
            it = li.end();
            m[key] = --it;
            return;
        }

        if(size)
            --size;
        else {
            m.erase(li.front().first);
            li.erase(li.begin());
        }

        li.push_back(make_pair(key, value));
        auto it = li.end();
        m[key] = --it;
    }
};

int main() {
	LRUCache cache(3);

	cache.set(1,1);
	cache.set(2,2);
	cache.set(3,3);
	cache.set(4,4);
	cout<<cache.get(4)<<"\n";
	cout<<cache.get(3)<<"\n";
	cout<<cache.get(2)<<"\n";
	cout<<cache.get(1)<<"\n";
	cache.set(5,5);
	cout<<cache.get(1)<<"\n";
	cout<<cache.get(2)<<"\n";
	cout<<cache.get(3)<<"\n";
	cout<<cache.get(4)<<"\n";
	cout<<cache.get(5)<<"\n";

	return 0;
}
