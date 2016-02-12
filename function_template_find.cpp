#include <iostream>
#include <string>
using namespace std;
static const size_t NOT_FOUND = (size_t)(-1);

template <typename T>
size_t Find(T& value, T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // Found it; return the index
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND
}

int main(int argc, char **argv){
  
      int xx = 3;
      int x[] = {1 ,2 ,3 ,4 };
      size_t arr_size = sizeof(x)/sizeof(int);
      size_t res =  Find<int>(xx, x, arr_size);
      cout << res << endl;
        return 0;

}
