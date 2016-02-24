//taken from http://msoucy.me
#include <cstdio>

template<int N> void bin() {
    bin<(N>>1)>(); 
    printf("%d",N%2);
}

template<> void bin<0>() {} // Base case

int main() {
    bin<42>(); // Print the binary representation of 42
    printf("\n");
    return 0;
}