#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>
#include <cstring>
using namespace std;
/*
 * While C++ defines struct assignment in a simple, convenient manner: 
struct A x, y;
...
x = y;
it does not for struct comparisons. Hence, to compare two struct instances for
equality: 
#include <string.h>

struct A x, y;

inline bool operator==(const A& x, const A& y)
{
    return (memcmp(&x, &y, sizeof(struct A)) == 0);
}
...
if (x == y)
    ...
Note that the operator overload must be done for every struct needing to be
compared, and the implementation of that overloaded operator is free of any
language help with type checking. The C++ way has an additional problem in that
just inspecting the (x == y) does not give a clue what is actually happening,
you have to go and find the particular overloaded operator==() that applies to
verify what it really does.

There's a nasty bug lurking in the memcmp() implementation of operator==(). The
layout of a struct, due to alignment, can have ‘holes’ in it. C++ does not
guarantee those holes are assigned any values, and so two different struct
instances can have the same value for each member, but compare different
because the holes contain different garbage.

To address this, the operator==() can be implemented to do a memberwise
compare. Unfortunately, this is unreliable because (1) if a member is added to
the struct definition one may forget to add it to operator==(), and (2)
floating point nan values compare unequal even if their bit patterns match.

There just is no robust solution in C++. 
 */
struct A {
    int a;
    int b;
};

inline bool operator==(const A& x, const A& y) {
    return ( memcmp(&x, &y, sizeof(struct A)) == 0);
}

int main(int argc, char **argv){
  
      struct A x, y;
      x.a = x.b = y.a = y.b = 1;
      
      if( x == y)
        cout << "x == y" << endl;    
      
        return 0;

}
