#include <iostream>

using namespace std;

class Vector {
private:
    int* storage;
    unsigned int capacity;
    unsigned int sz;
public:
    Vector() {
        capacity = 5;
        storage = new int[capacity];
        sz = 0;
    }
    Vector(unsigned int c) {
        capacity = c;
        storage = new int[capacity];
        sz = 0;
    }
    ~Vector() {
        delete [] storage;
    }
    unsigned int size() {
        return sz;
    }
    void push_back(int elem) {
        resize();
        storage[sz] = elem;
        sz++;
    }
    
    void shrink_to_fit() {
        if (sz == capacity) return;
        int* newStorage = new int[sz];
        for(unsigned int i = 0; i < sz; i++) {
            newStorage[i] = storage[i];
        }
        delete [] storage;
        storage = newStorage;
        capacity = sz;
    }
    
private:
    void resize() {
        if (sz == capacity) {
            unsigned int newCapacity = capacity * 1.5;
            int* newStorage = new int[newCapacity];
            for(unsigned int i = 0; i < sz; i++) {
                newStorage[i] = storage[i];
            }
            delete [] storage;
            storage = newStorage;
            capacity = newCapacity;
        }
    }
};

int main() {
    Vector v(4532);
    Vector a;
    for(int i = 0; i < 11; i++) {
        v.push_back(i*10);
    }
    cout << v.size() << endl;
    
    v.shrink_to_fit();
    return 0;    
}