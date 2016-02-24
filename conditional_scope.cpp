//taken from http://msoucy.me
#include <iostream>
using namespace std;

int someFunction(){
	return 1;
}

int main() {
	if(int ret = someFunction()) {
		cout << "ret: " << ret << endl;
	} else {
		cout << "ret: " << ret << endl;
	}
}

/*
Conditional Scope

Conditionals require expressions.
 The difference between expressions and statements is that expressions have a value.
  Variable declarations are expressions, not statements.

This means that this is possible, limiting the scope of the variable to the body of the if statement and 
its else clause(s)

if(int ret = someFunction()) {
    // Use ret
} else {
    // ret is 0
}
*/