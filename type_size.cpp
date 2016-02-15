#include <iostream>
using namespace std;
int main(int argc, char **argv){
  
    //integer types
    cout <<"the size of short " << sizeof(short) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of long: " << sizeof(long) << endl;
    //long long might not exist on all systems
    cout << "size of long long: " << sizeof(long long) << endl;
    //character and bool types
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of bool: " << sizeof(bool) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "sizeof double: " << sizeof(double) << endl;

    //long double might not exist on all systems
    cout << "sizeof long double: "<< sizeof(long double) << endl;
        return 0;

}
