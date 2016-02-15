#include <iostream>
#include <string>
using namespace std;
using MyInt = int;   //equivalent to typedef int MyInt
void test(int a){
    cout << "a: " << a << endl;
}
// equiv to typedef int (*FuncType)(int)
using FuncType = void (*)(int);
int main(int argc, char **argv){
        MyInt i = 0;
       cout << "i: " << i << endl; 

       FuncType func= test;
       cout << "calling functype: " <<  endl;
       func(10);


        return 0;

}
