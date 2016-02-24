//taken from http://msoucy.me
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> x = vector<int>(10); // Vector with 10 values
	generate(x.begin(),x.end(),[]() {
    	return (rand() % 100); // Make a "random" value
	});

	printf("Number of odd values: ",count_if(x.begin(), x.end(), [](int i){return i%2;}));


	// Harmless example
    printf("%d\n",[]{return 2+2;}());
    [](){}(); // Does absolutely nothing but scare future readers
    // And you can capture them with function pointers!
    int(*f)(int) = [](int x) {return x+2;};
    printf("%d\n",f(5));
    return 0;
}
/*
Lambdas (C++11)

Lambda functions are basically anonymous functions.
 These can make some of the standard library's functions much more usable.

vector<int> x = vector<int>(10); // Vector with 10 values
generate(x.begin(),x.end(),[]() {
    return (rand() % 100); // Make a "random" value
});
printf("Number of odd values: ",count_if(x.begin(), x.end(), [](int i){
    return i%2;}));

However they can VERY easily confuse anyone who is unaware:

#include <stdio.h>

int main() {
    // Harmless example
    printf("%d\n",[]{return 2+2;}());
    [](){}(); // Does absolutely nothing but scare future readers
    // And you can capture them with function pointers!
    int(*f)(int) = [](int x) {return x+2;};
    printf("%d\n",f(5));
    return 0;
}
*/
