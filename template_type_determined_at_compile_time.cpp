//taken from http://msoucy.me
#include <iostream>
using namespace std;

template<typename T> struct MyType {
    T data;
    MyType(T data):data(data) {}
};

int main() {
	MyType<int> x = MyType(5); // "typename T" matches "int"
}
/*
Templates

Templates are a way to write code that can be adapted to work on any type, such as containers. std::vector is a template, so vector<T> means roughly vector of some type T The syntax for declaring a template is:

template<typename T> struct MyType {
    T data;
    MyType(T data):data(data) {}
};

In this case, T is used as a type determined at compile time:

MyType<int> x = MyType(5); // "typename T" matches "int"


*/