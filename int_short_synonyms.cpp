#include <iostream>
#include <typeinfo>
using namespace std;
int main(int argc, char **argv){
    cout << typeid(signed).name() << endl;
    cout << typeid(signed int).name() << endl;
    cout << "------------------------------" << endl;
    cout << typeid(short).name() << endl;
    cout << typeid(short int).name() << endl;
    cout << typeid(signed short).name() << endl;

    return 0;
}
