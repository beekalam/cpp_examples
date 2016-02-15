#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv){
        cout << "please enter your name\n";
        string str;
        getline(cin,str);
        cout <<"Hello," << str <<"\n";
        return 0;

}
