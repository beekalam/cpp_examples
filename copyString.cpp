#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char* copyString(const char *str)
{
    char *ret = new char[strlen(str)+1];
    strcpy(ret,str);
    return ret;
}
int main(int argc, char **argv){
  
    char* str="some string";
    cout << copyString(str) << endl;
        return 0;

}
