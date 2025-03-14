#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;
#define ll long long
const int N = 1e5 + 2;
#define Fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);

template<class t>
class PriorityQueue {
    vector<t> v;// 0 based index
    int heap_size;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return (index * 2) + 1;
    }

    int rightChild(int index) {
        return (index * 2) + 2;
    }

    void reArrange(int index) {
        while (index != 0 && v[index] > v[parent(index)]) {
            swap(v[index], v[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int i) {
        int l = leftChild(i);
        int r = rightChild(i);
        int max = i;
        if (l < heap_size && v[l] > v[max])
            max = l;
        if (r < heap_size && v[r] > v[max])
            max = r;
        if (max != i) {
            swap(v[i], v[max]);
            heapify(max);
        }
    }

public:
    PriorityQueue() : heap_size(0) {
    }

    void push(int value) {
        v.push_back(value);
        heap_size++;
        int index = heap_size - 1;//because I'm dealing with zero based
        reArrange(index);
    }

    int size() const {
        return heap_size;
    }

    t top() {
        return v[0];
    }

    bool Empty() const {
        return v.empty();
    }

    t pop() {
        if (heap_size == 0) {
            throw out_of_range("PriorityQueue is empty");
        } else if (heap_size == 1) {
            t val = v.back();
            v.pop_back();
            heap_size--;
            return val;
        }
        t val = v.front();
        v[0] = v.back();
        v.pop_back();
        heap_size--;
        heapify(0);
        return val;
    }
};

int main() {
    Fast
    PriorityQueue<int> m;
    m.push(3);
    m.push(8);
    m.push(2);
    m.push(6);
    while (!m.Empty()) {
        cout << m.top() << "\n";
        m.pop();
    }
    PriorityQueue<char> p;
    p.push('d');
    p.push('z');
    p.push('a');
    while (!p.Empty()) {
        cout << p.top() << "\n";
        p.pop();
    }
    return 0;
}