//taken from http://msoucy.me
#include <iostream>
using namespace std;
/*
Most people have heard of the sizeof command, however, they are unaware that sizeof doesn't actually evaluate
 its contents.

The entire thing is performed at compile time, but not executed - it returns the size of the result 
of the expression, and compiles that in.

The original code doesn't actually make it to the executable.
*/
template <typename T, int N> char ( &Array( T(&)[N] ) )[N];
int main() {
	int x[5];

	cout << sizeof(Array(x)) << endl;
	
}