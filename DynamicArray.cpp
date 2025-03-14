#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Dynamic_array {
private:
    T* data;
    int all_size;
    int last = 0;
    void extend_array();
public:
    Dynamic_array(int num_elements = 100);
    ~Dynamic_array();
    void clear();
    void push_back(T val);
    void pop_back();
    void reverse();
    T back();
    bool empty();
    int size();
    int capacity();
    T& operator [](int index);
};

template<typename T>
Dynamic_array<T>::Dynamic_array(int num_elements) : last(num_elements), all_size(num_elements) {
    data = new T[num_elements];
}

template<typename T>
Dynamic_array<T>::~Dynamic_array() {
    this->clear();
}

template<typename T>
void Dynamic_array<T>::clear() {
    delete[] data;
    all_size = 0;
    last = 0;
}

template<typename T>
void Dynamic_array<T>::extend_array() {
    /* copying the data from the old array to the new one,
       then we delete the old data and assign the data pointer to the new extended array */
    T* new_data = new T[all_size + 1000];
    for (int i = 0; i < all_size; ++i) new_data[i] = data[i];
    delete[] data;
    data = new_data;
    all_size += 1000;
}

template<typename T>
void Dynamic_array<T>::push_back(T element) {
    if (last == all_size) this->extend_array();
    data[last++] = element;
}

template<typename T>
void Dynamic_array<T>::pop_back() {
    if (!all_size) throw runtime_error("cannot delete from an empty array");
    last--;
}

template<typename T>
void Dynamic_array<T>::reverse() {
    int l = 0, r = last - 1;
    while (l < r) {
        swap(data[l], data[r]);
        l++, r--;
    }
}

template<typename T>
T Dynamic_array<T>::back() {
    return data[all_size - 1];
}

template<typename T>
bool Dynamic_array<T>::empty() {
    return all_size;
}

template<typename T>
int Dynamic_array<T>::size() {
    return last;
}

template<typename T>
int Dynamic_array<T>::capacity() {
    return all_size;
}

template<typename T>
T& Dynamic_array<T>::operator[](int index) {
    if (index < 0 || index >= all_size) throw runtime_error("cannot access this index");
    return data[index];
}

int main() {
    Dynamic_array<int> dd(2);
    dd[0] = 5, dd[1] = 4;
    for (int i = 0; i < dd.size(); ++i) cout << dd[i] << " ";
    dd.push_back(20);
    dd.reverse();
    cout << "\n" << dd.size() << "\n" << dd.capacity() << "\n";
    for (int i = 0; i < dd.size(); ++i) cout << dd[i] << " ";
    return 0;
}