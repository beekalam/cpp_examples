#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template<typename T> class IsFunctionT
{
    private:
        typedef char One;
        typedef struct { char a[2]; } Two;
       template<typename U> static One test(...);
       template<typename U> static Two test(U (*)[1]);
    public:
       enum {Yes = sizeof(IsFunctionT<T>::test<T>(0)) == 1 };
};

int main(int argc, char **argv){
  
        typedef int (fp)(int);

        assert(IsFunctionT<fp>::Yes == 1);

        return 0;

}
