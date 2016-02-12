#include <iostream>
#include <set>
using namespace std;
int main(int argc, char **argv){
  
    int array[]={2,3,17,33, 45, 77};
    std::set<int> c(array,array+sizeof(array)/sizeof(array[0]));
    for(auto& v: c){
       cout << v << endl;
    }

    //todo
//    std::copy(c.begin(), c.end(),istream_iterator<int>(cin),
        return 0;

}
