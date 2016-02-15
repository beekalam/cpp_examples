#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;
int main(int argc, char **argv){
  vector<double>  values;
  values.reserve(20);    //memory for up to 20 elements
  vector<unsigned int> primes { 2u, 3u, 5u, 7u, 11u, 13u, 17u, 19u};
  vector<double> values2(20);    //capacity is 20 double values and there are 20 elements
  vector<long> numbers(20, 99L);   //size is 20 long values - all initialized with 99
  //you can initialize a vector<T> container when you create it with elements of type T
  //from another container. You specify the range of elements to be used as the
  //initial values using a pair of iterator container when you create it with elements of type T
  //from another container. You specify the range of elements to be used as the
  //initial values using a pair of iteratorss
  array<string, 5> words {"one", "two", "three", "four", "five"};
  vector<string> words_copy {begin(words), end(words)};
  //The words_copy vector will be intialized with the elements from the words
  //container. if you were to use move iterators to specify the initilizing range
  //for words_copy, the elements would be moved from the words array.Here's how you could
  //do that:
  vector<string> words_copy2 { make_move_iterator(begin(words)), 
                               make_move_iterator(end(words)) };
  // the words_copy vector  would be initialized as before. Because the elements
  // are moved rather than copied, the words array would now contain string
  // objects representing the empty string "".


        return 0;

}
