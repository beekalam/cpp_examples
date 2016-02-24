//taken from http://msoucy.me
#include <iostream>
using namespace std;

int main() {
	for(struct {int a; float b; } loop = {1, 2.0}; loop.a <10  ; loop.a++, loop.b++)
		cout << "a: " << loop.a << "   b: " << loop.b << endl;

	cout << "------------------" << endl;
}

/*
Everyone knows how to create a variable inside of a for loop:

for(int i=0;...;...) {
    ...
}

Because of how structures are declared, it's also possible to create one in the same place. 
This can be used to create several variables with different types, which is otherwise impossible
 while keeping their scope limited to the for loop.

for(struct { int a; float b; } loop = { 1, 2.0 }; ...; ...) {
    ...
}
*/