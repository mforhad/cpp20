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

    // vector with size parameter
    vector(size_t size) {
        _capasity = size;
        _data = new T[_capasity];
    }

    void push_back(T val) {
        cout<<"capasity: " << _capasity << endl;
        if (_size == _capasity - 1) {
            _capasity *= 2;
        }

        _data[_size++] = val;
    }

    T pop_back() {
        T val = _data[--_size];
        if (_size <= _capasity / 2) {
            _capasity /= 2;
        }
        return val;
    }

    size_t size() {return _size;}
    size_t capasity(){return _capasity;}
};

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
