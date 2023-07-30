#include<iostream>
#include<fstream>///file stream
#include<conio.h>
#include<vector>
#include<string>

int main(){
    std::string fname;
    std::cout<<"Enter file name: "<<std::endl;
    std::cin>>fname;

    std::ifstream fileR(fname);
   // std::ifstream fileR("helo.txt");  //creating a input file stream object
   

   if(fileR.is_open()){
    std::cout<<"file open"<<std::endl;
   }
    std::string inputStr; //stores each string(seperate by whitespace or endl) from  the file
    std::vector<std::string> names;
    while(fileR>>inputStr){   //like cin.. here it will return true untill the end is reached

        names.push_back(inputStr);
    }
    for(std::string n: names){   

        std::cout<<n<<std::endl;
    } 

    std::string line; 
    getline(fileR,line); // gets the sentences
    std::cout<<line<<std::endl;//already at the end of the file. so wont print anything



    fileR.close();
    return 0;
}