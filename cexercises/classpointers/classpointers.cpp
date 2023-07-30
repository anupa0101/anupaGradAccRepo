#include <iostream>
#include<conio.h>
using namespace std;

class Shape {
public:
  virtual void draw() { std::cout << "Drawing a shape" << std::endl; }
};

class Circle : public Shape {
public:
  int radius = 10;
  void draw() override { std::cout << "Drawing a circle" << std::endl; }
};

int main() {
  // Create an object of type Circle
  Circle myCircle, cirlex, *circleptr;

  // Create a pointer to Shape and point it to myCircle
  Shape* myShape = &myCircle;
  circleptr=&cirlex;


    cout<<circleptr->radius<<endl;
    circleptr->draw();


    myShape->draw(); 
    // Try to access the radius member of myCircle using the pointer to Shape
    //cout << myShape->radius <<endl; // Error: radius is not a member of Shape


  return 0;
}
