#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class vector{
    size_t _capasity = 1;
    size_t _size = 0;
    T* _data;
public:
    // default constructor
    vector(){}

    // constructor with sized parameter
    vector(size_t size) {
        _capasity = size;
        _data = new T[_capasity];
    }

    // push an item to the vector
    void push_back(T val) {
        cout<<"capasity: " << _capasity << endl;
        if (_size == _capasity - 1) {
            _capasity *= 2;
        }

        _data[_size++] = val;
    }

    // pop the latest item from the vector
    T pop_back() {
        T val = _data[--_size];
        if (_size <= _capasity / 2) {
            _capasity /= 2;
        }
        return val;
    }

    // get vector size
    size_t size() {return _size;}

    // get capasity of the vector for test purpose
    size_t capasity(){return _capasity;}
};

// Main function for testing the vector
int main() {
    vector<int> v;
    vector<double> v1(5);

    for (int i = 0; i<=10; i++){
        v.push_back(i);
    }

    for (size_t i = 0; i<= 10; i++) {
        cout<<"capasity: " << v.capasity() << endl;
        cout<<"v["<<i<<"] : " << v.pop_back()<<endl;
    }
    
    return 0;
}
