#include <iostream>
#include <string>
using namespace std;

template<int n> class factorial
{
    public:
        enum { result = n * factorial<n-1>::result };
};

template<> class factorial<1>
{
    public:
        enum { result = 1};
};

int main(int argc, char **argv){
  
      cout << factorial<4>::result << endl;

        return 0;

}
