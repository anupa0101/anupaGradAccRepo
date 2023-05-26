#include <iostream>
#include <array>/////////////////////////


void print_array(std::array<int,5 > ary)    // templsatized arrys ARE PASSED BY VALUE NOT REFFERENCE LIKE ANY OTHER NORMAL VARIABLE
{// ARRAY SIZE IS NEEDED. NOT DYNAMIC SIZE
    for(int i=0; i<ary.size();i++)   // size function works inside fucntions too. for normal arrays it wont as its a pointer
    {                                 //however size gives the intially defined size=5
        std::cout<<ary[i]<<"\t";
    }
}

void print_array_only_required(std::array<int,5 > ary)   { // to print the required number of elements. sometimes the rest isnt defined yet
    for(int i=0; i<ary.size();i++)   //
    {                                 /
        std::cout<<ary[i]<<"\t";
    }
}

void change_array(std::array<int,5> &ary)    // arrayS ARE PASSED BY VALUE NOT REFFERENCE LIKE ANY OTHER NORMAL VARIABLE. HERE PASSED AS REFFERENCE 
{
    std::cout << "\nchanging array"<< std::endl;
    ary={1,2,4,5};  //CAN ASSIGN LIKE THIS. in normal arrays will have to iterate 
}


int main() {




  // Create a array to store a sequence of numbers
  std::array<int,5> v;
  v={1,2};



  // Print the number of elements in the array
  std::cout << "The array has " << v.size() << " elements" << std::endl;

  // Check if the array is empty
  if (v.empty()) {
    std::cout << "The array is empty" << std::endl;
  } else {
    std::cout << "The array is not empty" << std::endl;
  }

  // Print the first and last elements in the array
  std::cout << "The first element in the array is " << v.front() << std::endl;
  std::cout << "The last element in the array is " << v.back() << std::endl;




  // Check if the array is empty again
  if (v.empty()) {
    std::cout << "The array is empty" << std::endl;
  } else {
    std::cout << "The array is not empty" << std::endl;
  }

  print_array(v);

  change_array(v);
  print_array(v);

  return 0;
}



  

