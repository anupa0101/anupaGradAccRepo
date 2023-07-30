
#include <iostream>
#include <vector>


void print_vector(std::vector<std::vector<int>> vect)  {  // CALLING 2D NESTED VECTORS
    for(int i=0; i<vect.size();i++)   // size function works inside fucntions too. for arrays it wont as its a pointer
    {
        for(int j=0; j<vect[i].size();j++)
        {
            std::cout<<vect[i][j]<<"\t";
        }
        std::cout<<std::endl;

    }
}

void change_vector(std::vector<std::vector<int>> &vect) {   //  PASSED BY VALUE by default but use &!!!!!!!!!!!
   for(int i=0; i<vect.size();i++)   // size function works inside fucntions too. for arrays it wont as its a pointer
    {
        for(int j=0; j<vect[i].size();j++)
        {
            std::cin>>vect[i][j];
            std::cin.ignore();
        }
    }

}

int main() {

  // Create a nested 2d vector to store a sequence of numbers
  std::vector<std::vector<int>> nestedV;
    nestedV={{1,2,3},{1,2},{4,3,4,5,6}};
  // Add some numbers to the vector
   print_vector(nestedV);
  nestedV.push_back({5,5,5});
  
  nestedV[3].push_back(1);
  
  nestedV[1].push_back(2);
  
  nestedV.push_back({5,5,5});
    print_vector(nestedV);

  // Print the number of elements in the vector
  std::cout << "The vector has " << nestedV.size() << " elements" << std::endl;

  // Check if the vector is empty
  if (nestedV.empty()) {
    std::cout << "The vector is empty" << std::endl;
  } else {
    std::cout << "The vector is not empty" << std::endl;
  }

  // Print the first and last elements in the vector
  std::cout << "The first element in the first element of the vector is " << nestedV[0].front() << std::endl;
  std::cout << "The last element in the first element of the  vector is " << nestedV[0].back() << std::endl;



  // Reserve space for 10 elements in the vector
  nestedV.reserve(10);

  // Clear the vector
  nestedV.clear();

  // Check if the vector is empty again
  if (nestedV.empty()) {
    std::cout << "The vector is empty" << std::endl;
  } else {
    std::cout << "The vector is not empty" << std::endl;
  }
  nestedV.push_back({3});
  print_vector(nestedV);

  change_vector(nestedV); // we need to define the size of the vector as well. or else can modify(replace) the currently avaiable size and structure only
  print_vector(nestedV);

  return 0;
}



  

