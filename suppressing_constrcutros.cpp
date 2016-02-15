#include <iostream>
class Shape{
public:
    Shape(const Shape&)=delete;             //no copy operation
    Shape& operator=(const Shape&)=delete;
  
    Shape(Shape&&)=delete;
    Shape& operator=(Shape&&)=delete;     //no move operations

    ~Shape();
}
int main(int argc, char **argv){
     
    return 0;
}
