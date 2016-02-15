#include <iostream>
template<typename T>
class Vector{
private:
    T *elem;
    int sz;
public:
    Vector(int s);
    ~Vector(){delete[] elem; }
    T& operator[](int i);
    const T& operator[](int i)const;
    int size() const { return sz;}
};
template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0) throw Negative_size{};
    elem = new T[s];
    sz = s;
}


template<typename T>
const T& Vector<T>::operator[](int i)const
{
    if (i<0 || size() <= i)
        throw out_of_range{"vector::operator[]"};
    return elem[i];
}
//to support range-for loop for our vector, we must
//define suitable begin and end functions
template<typename T>
T* begin(Vector<T>& x)
{
    return &x[0];
}

template<typename T>
T* end(Vector<T>& x)
{
    return x.begin() + x.size();
}


//test for based loop
void f2(const Vector<string>& vs)
{
    for(auto& s: vs)
        cout << s << "\n";
}
int main(int argc, char **argv){
    Vector<char> vc(200);
    Vector<string> vs(17);
    Vector<list<int>> vli(45);

    return 0;
}
