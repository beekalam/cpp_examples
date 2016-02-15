#include <iostream>
#include <vector>
#include <istream>
using namespace std;
int main(int argc, char **argv){
        cout <<"the alignment of a char: " << alignof('c') <<endl;
        cout <<"the alignment of an int: " << alignof(1) << endl;
        cout <<"the alignment of a double: " << alignof(2.0) << endl;
        int a[20];
        cout <<"the alignment of a[20]: " << alignof(a) << endl;
        return 0;

}
