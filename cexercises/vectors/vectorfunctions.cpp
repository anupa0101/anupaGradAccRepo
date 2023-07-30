#include <iostream>
#include <vector>


void print_vector(std::vector<int> vect)    // VECTORS ARE PASSED BY VALUE NOT REFFERENCE LIKE ANY OTHER NORMAL VARIABLE
{
    for(int i=0; i<vect.size();i++)   // size function works inside fucntions too. for arrays it wont as its a pointer
    {
        std::cout<<vect[i]<<"\t";
    }
}

void change_vector(std::vector<int> &vect)    // VECTORS ARE PASSED BY VALUE NOT REFFERENCE LIKE ANY OTHER NORMAL VARIABLE. HERE PASSED AS REFFERENCE 
{
    std::cout << "/nchanging vector"<< std::endl;
    vect={1,2,4,5};
}


int main() {




  // Create a vector to store a sequence of numbers
  std::vector<int> v; // use std::vector<int> v(3,1) to create vector of 3 and fill with 1. v(3) will create vector of size 3 and fill by default 0

  // Add some numbers to the vector
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  

  // Print the number of elements in the vector
  std::cout << "The vector has " << v.size() << " elements" << std::endl;

  // Check if the vector is empty
  if (v.empty()) {
    std::cout << "The vector is empty" << std::endl;
  } else {
    std::cout << "The vector is not empty" << std::endl;
  }

  // Print the first and last elements in the vector
  std::cout << "The first element in the vector is " << v.front() << std::endl;
  std::cout << "The last element in the vector is " << v.back() << std::endl;

     v.pop_back(); //delete the last element 
    std::cout << "The last element in the vector after pop_back is " << v.back() << std::endl;

  // Reserve space for 10 elements in the vector
  v.reserve(10);//avoids realcoating of the heap which is expensive

  // Clear the vector
  v.clear();

  // Check if the vector is empty again
  if (v.empty()) {
    std::cout << "The vector is empty" << std::endl;
  } else {
    std::cout << "The vector is not empty" << std::endl;
  }
  v.push_back(3);
  print_vector(v);

  change_vector(v);
  print_vector(v);

  return 0;
}



  

