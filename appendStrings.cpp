#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char* appendStrings(const char* str1,const char* str2,const char* str3)
{
    char *result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}
int main(int argc, char **argv){
    char* str1="string1";
    char* str2 = " string2 ";
    char* str3 = " string3 ";
    cout << appendStrings(str1, str2, str3) << endl;
    return 0;

}
