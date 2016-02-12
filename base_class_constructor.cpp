#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A()
    {
    }
};

class B : A
{
public:
    B(int x) : A() //Call base class constructor
    {
    }
};

int main(int argc, char **argv){
  
        return 0;

}
