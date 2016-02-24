//taken from http://msoucy.me
#include <cstdio>

int f(int x) {
    return x+1;
}
int g(int x) {
    return x*2;
}
int h(int x) {
    return x-3;
}

typedef int(*FunctionPointer)(int); // Create a type FunctionPointer
// This type points to a function taking an int and returning an int
int main() {
    FunctionPointer todo[3] = {f,g,h}; // Array of function pointers
    int x=10;
    for(unsigned i=0;i < 3;i++) {
        x = todo[i](x);
    }
    // Result should be 19
    printf("Result>\t%d\n",x);
    return 0;
}

/*
Function Pointers

Since you can create a pointer to a variable, it makes sense that you can create a pointer to a function. The syntax is rather ugly though...

#include <stdio.h>

int f(int x) {
    return x+1;
}
int g(int x) {
    return x*2;
}
int h(int x) {
    return x-3;
}

typedef int(*FunctionPointer)(int); // Create a type FunctionPointer
// This type points to a function taking an int and returning an int
int main() {
    FunctionPointer todo[3] = {f,g,h}; // Array of function pointers
    int x=10;
    for(unsigned i=0;i < 3;i++) {
        x = todo[i](x);
    }
    // Result should be 19
    printf("Result>\t%d\n",x);
    return 0;
}
*/