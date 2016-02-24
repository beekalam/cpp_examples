//taken from http://msoucy.me
#include <iostream>
using namespace std;

int main() {
	int x = 0xabc;
	// Gets the lowest hex value of a variable
	cout << "0123456789abcdef"[x & 0xf] ;

	cout << endl;
	// Indexes into the string, but does the same thing
	cout << (x & 0xf)["0123456789abcdef"];

	cout << endl;
}
/*
By extension

String literals have a type of const char*.

It's perfectly legal to index a const char*.

Because of this, you're allowed to do something like this:

// Gets the lowest hex value of a variable
"0123456789abcdef"[x & 0xf];
// Indexes into the string, but does the same thing
(x & 0xf)["0123456789abcdef"];
*/