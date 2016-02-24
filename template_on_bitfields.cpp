#include <cstdio>

template<int N> class BitField {
    unsigned x:N; // Generate a compiler error if N==0
};

int main() {
    //Bitfield<2> x; // Booleans "graduate" to integers, so this is legal
    //Bitfield<(1>2)> y; // Creates a zero-width bitfield, so illegal
    return 0;
}
/*
Templates on bitfields

Templates can be used for integral values, not just types. They must be calculatable in compile-time. This means that a template value can be used in the place of any other compile-time value.

#include <cstdio>

template<int N> class BitField {
    unsigned x:N; // Generate a compiler error if N==0
};

int main() {
    Bitfield<2> x; // Booleans "graduate" to integers, so this is legal
    //Bitfield<(1>2)> y; // Creates a zero-width bitfield, so illegal
    return 0;
}
*/