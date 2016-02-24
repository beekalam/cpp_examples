//taken from http://msoucy.me
#include <iostream>
using namespace std;

int foo() {return 5;}
int bar() {return 6;}
int baz() {return 7;}

int main() {
	int y = (foo(),bar(),baz());
	cout <<"y: " << y << endl;   //outputs 7


}
/*
Commas are useful for more than just separating function arguments:

int foo() {return 5;}
int bar() {return 6;}
int baz() {return 7;}

int x = (foo(),bar(),baz());
cout << x; // Outputs 7

You may be familiar with the comma in for loops and variable declarations:

int x=2,y=3;
for(int i=0,j=2;i<j;i++) { //do stuff}

Now try sticking them in, say, an if statement:

int x=0;
if(cin>>x,x*=2,x<8) { // do stuff }
*/